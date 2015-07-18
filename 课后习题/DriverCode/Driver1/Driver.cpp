#include "Driver.h"

#pragma INITCODE

NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObj , IN PUNICODE_STRING pRegistryPath)
{
	GetCurFunctionAddrByASM();
	GetCurFunctionAddrByC();

	NTSTATUS status;
	KdPrint(("Enter DriverEntry\n"));

	pDriverObj->DriverUnload = HelloDDKUnload;
	pDriverObj->MajorFunction[IRP_MJ_CREATE] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_CLOSE] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_WRITE] = HelloDDKDispatchRoutine;
	pDriverObj->MajorFunction[IRP_MJ_READ] = HelloDDKDispatchRoutine;

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

	
	RtlInitUnicodeString(&symLinkName, L"\\??\\HelloDDK");
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

void GetCurFunctionAddrByASM()
{
	//公式：[[KeServiceDescriptorTable]+0x7A*4]

	//------------------------使用汇编读取指定索引的函数地址---------------------------------------------
	ULONG SSDT_NtOpenProcess_Cur_Addr;

	__asm
	{
		int 3
		push ebx//现将需要使用到的寄存器入栈
		push eax

		mov ebx,KeServiceDescriptorTable//取sstd表的地址
		mov ebx,[ebx]//取出第一个地址，即函数列表的基址
		mov eax,0x7a //7A是openprocess函数在ssdt中的索引
		shl eax,2 //左移2位，即*4
		add ebx,eax //[KeServiceDescriptorTable]+0x7A*4
		mov ebx,[ebx] //
		mov SSDT_NtOpenProcess_Cur_Addr, ebx//将函数地址保存在变量中

		pop eax//恢复寄存器的值
		pop ebx
	}

	KdPrint(("OpenProcess Addr = %0x --- GetCurFunctionAddrByASM()\n\n",SSDT_NtOpenProcess_Cur_Addr));

}

void GetCurFunctionAddrByC()
{
	//----------------------使用C语言读取指定索引的函数地址----------------------------------------

	__asm{
		int 3
	}

	long* SSDT_Addr,SSDT_NtOpenProcess_Cur_Addr,t_addr;

	t_addr = (LONG)KeServiceDescriptorTable->ServiceTableBase;//取SSDT表基址
	KdPrint(("当前ServiceTableBase地址为:%0x ---GetCurFunctionAddrByC()\n",t_addr));

	SSDT_Addr = (PLONG)(t_addr+0x7A*4);//基址+偏移
	KdPrint(("当前t_addr+0x7a*4 = %0x ---GetCurFunctionAddrByC()\n",SSDT_Addr));

	SSDT_NtOpenProcess_Cur_Addr = *SSDT_Addr;//取偏移处的值
	KdPrint(("当前OpenProcess Addr = %0x ---GetCurFunctionAddrByC()\n\n",SSDT_NtOpenProcess_Cur_Addr));
 
}

