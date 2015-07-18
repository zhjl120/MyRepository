#include "Driver.h"

#pragma INITCODE

#define HOOK_CODE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS) 
#define UNHOOK_CODE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS) 

NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObj , IN PUNICODE_STRING pRegistryPath)
{
	NTSTATUS status;
	KdPrint(("Enter DriverEntry\n"));

	pDriverObj->DriverUnload = HelloDDKUnload;
	pDriverObj->MajorFunction[IRP_MJ_CREATE] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_CLOSE] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_WRITE] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_READ] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_DEVICE_CONTROL] = MjDeviceContorl;

	status = CreateDevice(pDriverObj);
	KdPrint(("Leave DriverEntry\n"));
	return status;
}

#pragma INITCODE

NTSTATUS CreateDevice(IN PDRIVER_OBJECT pDriverObj)
{
	NTSTATUS status;
	PDEVICE_OBJECT pDeviceObj;
	PDEVICE_EXTENSION pDevExt;
	UNICODE_STRING symLinkName;
	UNICODE_STRING devName;

	KdPrint(("Enter CreateDevice\n"));

	RtlInitUnicodeString(&devName , L"\\Device\\MyDDKDevice");

	status = IoCreateDevice(pDriverObj, sizeof(DEVICE_EXTENSION), &devName, 
							FILE_DEVICE_UNKNOWN, 0, TRUE, &pDeviceObj);
	
	if(! NT_SUCCESS(status))
		return status;

	pDeviceObj->Flags |= DO_BUFFERED_IO;
	pDevExt = (PDEVICE_EXTENSION)pDeviceObj->DeviceExtension;
	pDevExt->pDevice = pDeviceObj;
	pDevExt->ustrDeviceName = devName;

	
	RtlInitUnicodeString(&symLinkName, L"\\??\\YouCaiHua");
	pDevExt->ustrSymLinkName =symLinkName;
	status = IoCreateSymbolicLink(&symLinkName, &devName);

	if(!NT_SUCCESS(status))
	{
		IoDeleteDevice(pDeviceObj);
		return status;
	}
	
	KdPrint(("Leave CreateDevice\n"));

	return STATUS_SUCCESS;
}

#pragma	PAGEDCODE

VOID HelloDDKUnload( IN PDRIVER_OBJECT pDriverObject )
{
	PDEVICE_OBJECT pNextObj;
	KdPrint(("Enter HelloDDKUnload\n"));
	pNextObj = pDriverObject->DeviceObject;

	while (pNextObj != NULL)
	{
		PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pNextObj->DeviceExtension;
		UNICODE_STRING pLinkName = pDevExt->ustrSymLinkName;
		IoDeleteSymbolicLink(&pLinkName);
		pNextObj = pNextObj->NextDevice;
		IoDeleteDevice(pDevExt->pDevice);
	}
	KdPrint(("Leave HelloDDKUnload\n"));

	if(bIsHook)
		UnHookNtOpenprocess();
}

#pragma PAGEDCODE

NTSTATUS HelloDDKDispatchRoutine( IN PDEVICE_OBJECT pDeviceObj , IN PIRP pIrp )
{
	NTSTATUS status = STATUS_SUCCESS;
	
	KdPrint(("Enter HelloDDKDispatchROutine\n"));

	pIrp->IoStatus.Status = status;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp,IO_NO_INCREMENT);
	KdPrint(("Leave HelloDDKDispatchRouttine\n"));

	return status;
}

NTSTATUS MjDeviceContorl( IN PDEVICE_OBJECT pDeviceObj , IN PIRP pIrp )
{
	KdPrint(("Enter MjDeviceContorl\n"));

	NTSTATUS status = STATUS_SUCCESS;

	PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(pIrp);

	ULONG nInBuffLength = stack->Parameters.DeviceIoControl.InputBufferLength;
	ULONG nOutBuffLength = stack->Parameters.DeviceIoControl.OutputBufferLength;

	ULONG nCode = stack->Parameters.DeviceIoControl.IoControlCode;

	switch (nCode)
	{
	case HOOK_CODE:
		{
			int* pInBuff = (int*)pIrp->AssociatedIrp.SystemBuffer;//缓冲区访问模式或直接访问模式
		
			__asm
			{
				mov eax,pInBuff
				mov ebx,[eax]
				mov MyPid,ebx
			}
		
			int* pOutBuff = (int*)pIrp->AssociatedIrp.SystemBuffer;

			__asm
			{
				mov eax,1
				mov ebx,pOutBuff
				mov [ebx],eax
			}

			HookNtOpenProcess();
			break;
		}

	case UNHOOK_CODE:
		UnHookNtOpenprocess();
		break;
	}
	

	pIrp->IoStatus.Information = 4;//Oprate 4 byte, return value:dwWrite
	pIrp->IoStatus.Status = STATUS_SUCCESS;

	IoCompleteRequest(pIrp, IO_NO_INCREMENT);

	KdPrint(("Leave MjDevcieControl\n"));

	return STATUS_SUCCESS;
}

//--------------------------------------
#pragma PAGEDCODE

NTSTATUS HookNtOpenProcess()
{
	KdPrint(("Enter HookNtOpenProcess\n"));
	
	LONG* SSDT_Addr, t_addr;

	t_addr = (LONG)KeServiceDescriptorTable->ServiceTableBase;//获取SSDT地址

	SSDT_Addr = (PLONG)(t_addr + 0x7a*4);//获取索引为0x7A的函数地址

	RealNtOpenProcessAddr = *SSDT_Addr;//全局变量，用于保存源地址，以供恢复时使用

	pRealNtOpenProcess = (NTOPENPROCESS*)RealNtOpenProcessAddr;

	KdPrint(("真实NtOpenProcess地址：%x\n",(int)RealNtOpenProcessAddr));
	KdPrint(("伪造NtOpenProcess地址：%x\n",(int)MyNtOpenProcess));

	__asm
	{
		cli
			mov eax,cr0
			and eax,not 10000h
			mov cr0,eax
	}

	*SSDT_Addr = (ULONG)MyNtOpenProcess;

	__asm
	{
		mov eax,cr0
			or eax,10000h
			mov cr0,eax
			sti
	}

	bIsHook = true;

	KdPrint(("Leave HookNtOpenProcess\n"));

	return STATUS_SUCCESS;
}


#pragma PAGEDCODE

NTSTATUS UnHookNtOpenprocess()
{
	KdPrint(("Enter UnHookNtOpenprocess\n"));

	ULONG NtOpenProcessAddr;

	NtOpenProcessAddr = (ULONG)KeServiceDescriptorTable->ServiceTableBase +0x7a*4;

	KdPrint(("NtOpenProcessAddr = %x\n",NtOpenProcessAddr));

	if (bIsHook)
	{
		__asm
		{
			cli
				mov eax,cr0
				and eax,not 10000h
				mov cr0,eax
		}

		KdPrint(("Hook before :%x\n",*((ULONG*)NtOpenProcessAddr)));
		*((ULONG*)NtOpenProcessAddr) = (ULONG)RealNtOpenProcessAddr;
		KdPrint(("Hook after :%x\n",*((ULONG*)NtOpenProcessAddr)));

		__asm
		{
			mov eax,cr0
				or eax,10000h
				mov cr0,eax
				sti
		}

		bIsHook = false;
	}

	KdPrint(("Leave UnHookNtOpenprocess\n"));

	return STATUS_SUCCESS;
}


#pragma PAGEDCODE

NTSTATUS MyNtOpenProcess( __out PHANDLE ProcessHandle, __in ACCESS_MASK DesiredAccess, __in POBJECT_ATTRIBUTES ObjectAttributes, __in_opt PCLIENT_ID ClientId )
{
	//KdPrint(("Enter MyNtOpenProcess\n"));

	NTSTATUS result;

	if(ClientId != NULL)
	{
		HANDLE Pid = ClientId->UniqueProcess;
	//	KdPrint(("Pid = %d \n",(int*)Pid));

		if (Pid == MyPid)
		{
		//	KdPrint(("该进程被保护！\n"));

			ProcessHandle = NULL;
			result = STATUS_ACCESS_DENIED;
			EP = PsGetCurrentProcess();
			KdPrint(("Process Name :%s\n",(PTSTR)((ULONG)EP+0x174)));
		}
		else
		{
			result = (NTSTATUS)pRealNtOpenProcess(ProcessHandle, DesiredAccess, ObjectAttributes, ClientId);
		}
	}

	return result;
}



