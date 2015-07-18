#include "Driver.h"

#pragma INITCODE

NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObj , IN PUNICODE_STRING pRegistryPath)
{
	__asm int 3;
	 
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

