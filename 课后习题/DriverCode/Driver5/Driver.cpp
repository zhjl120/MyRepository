#include "Driver.h"

#pragma INITCODE

#define add_code CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS) 
//METHOD_NEITHER：表示使用其它访问模式

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
	case add_code:
		int nNum1 = 0, nNum2 = 0;

		//int* pInBuff = (int*)pIrp->AssociatedIrp.SystemBuffer;//缓冲区访问模式或直接访问模式
		int* pInBuff = (int*)stack->Parameters.DeviceIoControl.Type3InputBuffer;
		
		__try
		{
			ProbeForRead(pInBuff,nInBuffLength,4);//pInBuff可能不可读，需要做判断,参数3为对齐方式
		}__except(EXCEPTION_EXECUTE_HANDLER)
		{
			KdPrint(("ProbeForRead Error\n"));
		}

		__asm
		{
			mov eax,pInBuff
			mov ebx,[eax]
			mov nNum1,ebx
			mov ebx,[eax+4]
			mov nNum2,ebx
		}

		KdPrint(("Driver Print: Num1=%d, Num2=%d\n",nNum1, nNum2));

		int nResult = nNum1 + nNum2;

		int* pOutBuffer = (int*)pIrp->UserBuffer;
		//获取输出buffer

		//__try
		//{
		//	ProbeForWrite(pOutBuffer,nOutBuffLength,4);
		//}
		//__except(EXCEPTION_EXECUTE_HANDLER)
		//{
		//	KdPrint(("ProbeForWrite Error\n"));//判读缓冲区是否可写
		//}

		__asm
		{
			mov eax,nResult
			mov ebx,pOutBuffer
			mov [ebx],eax
		}

		KdPrint(("Driver Print: Num1+Num2 = %d\n",nResult));

		break;
	}

	pIrp->IoStatus.Information = 4;//Oprate 4 byte, return value:dwWrite
	pIrp->IoStatus.Status = STATUS_SUCCESS;

	IoCompleteRequest(pIrp, IO_NO_INCREMENT);

	KdPrint(("Leave MjDevcieControl\n"));

	return STATUS_SUCCESS;
}

