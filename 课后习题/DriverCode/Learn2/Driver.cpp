#include "Driver.h"

#pragma INITCODE
NTSTATUS DriverEntry( IN PDRIVER_OBJECT pDriverObj, IN PUNICODE_STRING RegistryPath )
{
	KdPrint(("Enter DriverEntry\n"));

	pDriverObj->DriverExtension->AddDevice = HelloWDMAddDevice;
	pDriverObj->MajorFunction[IRP_MJ_PNP] = HelloWDMPnp;
	pDriverObj->MajorFunction[IRP_MJ_DEVICE_CONTROL] =
	pDriverObj->MajorFunction[IRP_MJ_CREATE] =
	pDriverObj->MajorFunction[IRP_MJ_READ] = 
	pDriverObj->MajorFunction[IRP_MJ_WRITE] = HelloWDMDispatchRoutine;
	pDriverObj->DriverUnload = HelloWMDUnload;

	KdPrint(("Leave DriverEntry\n"));

	return STATUS_SUCCESS;
}

#pragma PAGEDCODE
NTSTATUS HelloWDMAddDevice( IN PDRIVER_OBJECT DriverObj, IN PDEVICE_OBJECT PhysicalDeviceObj )
{
	NTSTATUS status;
	PDEVICE_OBJECT fdo;
	UNICODE_STRING devName;
	UNICODE_STRING symLinkName;
	PDEVICE_EXTENSION pdx;

	PAGED_CODE();
	KdPrint(("Enter HelloWDMAddDevice\n"));
	
	RtlInitUnicodeString(&devName,L"\\Device\\MyWDMDevice");
	status = IoCreateDevice(DriverObj, sizeof(DEVICE_EXTENSION), &devName, FILE_DEVICE_UNKNOWN, 0, FALSE, &fdo);
	if(!NT_SUCCESS(status))
		return status;

	pdx = (PDEVICE_EXTENSION)fdo->DeviceExtension;
	pdx->fdo = fdo;
	pdx->NextStackDevice = IoAttachDeviceToDeviceStack(fdo, PhysicalDeviceObj);
	
	RtlInitUnicodeString(&symLinkName,L"\\DosDevices\\HelloWDM");
	pdx->ustrDeviceName = devName;
	pdx->ustrSymLinkName = symLinkName;
	status = IoCreateSymbolicLink(&symLinkName, &devName);

	if(! NT_SUCCESS(status))
	{
		IoDeleteSymbolicLink(&pdx->ustrSymLinkName);
		status = IoCreateSymbolicLink(&symLinkName, &devName);
		if(! NT_SUCCESS(status))
			return status;
	}

	fdo->Flags |= DO_BUFFERED_IO | DO_POWER_PAGABLE;
	fdo->Flags &= ~DO_DEVICE_INITIALIZING;

	KdPrint(("Leave HelloWMDAddDevice\n"));

	return STATUS_SUCCESS;
}

#pragma PAGEDCODE
NTSTATUS DefaultPnpHandler(PDEVICE_EXTENSION pdx,PIRP Irp)
{
	PAGED_CODE();
	KdPrint(("Enter DefaultPnpHander\n"));
	IoSkipCurrentIrpStackLocation(Irp);
	KdPrint(("Leave DefaultPnpHander\n"));
	return IoCallDriver(pdx->NextStackDevice,Irp);
}

#pragma PAGEDCODE
NTSTATUS HandleRemoveDevice(PDEVICE_EXTENSION pdx,PIRP Irp)
{
	NTSTATUS status;

	PAGED_CODE();
	KdPrint(("Entry HandleRemoveDevice\n"));

	Irp->IoStatus.Status = STATUS_SUCCESS;
	status = DefaultPnpHandler(pdx, Irp);
	IoDeleteSymbolicLink(&pdx->ustrSymLinkName);

	if(pdx->NextStackDevice)
		IoDetachDevice(pdx->NextStackDevice);

	IoDeleteDevice(pdx->fdo);
	KdPrint(("Leave HandleRemoveDevice\n"));

	return status;
}

#pragma PAGEDCODE
NTSTATUS HelloWDMPnp( IN PDEVICE_OBJECT fdo, IN PIRP Irp )
{
//	static NTSTATUS (*fcntab[])(PDEVICE_EXTENSION pdx,PIRP Irp) = {
//		DefaultPnpHandler,DefaultPnpHandler,HandleRemoveDevice,
//		DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,
//		DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,
//		DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,
//		DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,
//		DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,DefaultPnpHandler,
//		DefaultPnpHandler,
//	};
//
//#if DBG
//	static char* fcnname[]={
//		"IRP_MN_START_DEVICE",
//		"IRP_MN_QUERY_REMOVE_DEVICE",
//		"IRP_MN_REMOVE_DEVICE",
//		"IRP_MN_CANCEL_REMOVE_DEVICE",
//		"IRP_MN_STOP_DEVICE",
//		"IRP_MN_QUERY_STOP_DEVICE",
//		"IRP_MN_CANCEL_STOP_DEVICE",
//		"IRP_MN_QUERY_DEVICE_RELATIONS",
//		"IRP_MN_QUERY_INTERFACE",
//		"IRP_MN_QUERY_CAPABILITIES",
//		"IRP_MN_QUERY_RESOURCES",
//		"IRP_MN_QUERY_RESOURCE_REQUIREMENTS",
//		"IRP_MN_QUERY_DEVICE_EXIT",
//		"IRP_MN_FILTER_RESOURCE_REQUITREMENTS",
//		"",
//		"IRP_MN_READ_CONFIG",
//		"IRP_MN_WIRTE_CONFIG",
//		"IRP_MN_EJECT",
//		"IRP_MN_SET_LOCK",
//		"IRP_MN_QUERY_ID",
//		"IRP_MN_QUERY_PNP_DEVICE_STATE",
//		"IRP_MN_QUERY_BUS_INFORMATION",
//		"IRP_MN_DEVICE_USAGE_NOTIFICATION",
//		"IRP_MN_SURPRISE_REMOVAL",
//	};
//
////	KdPrint(("PNP Request (%s)\n",fcnname[fcn]));
//
//#endif

	static NTSTATUS (*fcntab[])(PDEVICE_EXTENSION pdx, PIRP Irp) = 
	{
		DefaultPnpHandler,		// IRP_MN_START_DEVICE
		DefaultPnpHandler,		// IRP_MN_QUERY_REMOVE_DEVICE
		HandleRemoveDevice,		// IRP_MN_REMOVE_DEVICE
		DefaultPnpHandler,		// IRP_MN_CANCEL_REMOVE_DEVICE
		DefaultPnpHandler,		// IRP_MN_STOP_DEVICE
		DefaultPnpHandler,		// IRP_MN_QUERY_STOP_DEVICE
		DefaultPnpHandler,		// IRP_MN_CANCEL_STOP_DEVICE
		DefaultPnpHandler,		// IRP_MN_QUERY_DEVICE_RELATIONS
		DefaultPnpHandler,		// IRP_MN_QUERY_INTERFACE
		DefaultPnpHandler,		// IRP_MN_QUERY_CAPABILITIES
		DefaultPnpHandler,		// IRP_MN_QUERY_RESOURCES
		DefaultPnpHandler,		// IRP_MN_QUERY_RESOURCE_REQUIREMENTS
		DefaultPnpHandler,		// IRP_MN_QUERY_DEVICE_TEXT
		DefaultPnpHandler,		// IRP_MN_FILTER_RESOURCE_REQUIREMENTS
		DefaultPnpHandler,		// 
		DefaultPnpHandler,		// IRP_MN_READ_CONFIG
		DefaultPnpHandler,		// IRP_MN_WRITE_CONFIG
		DefaultPnpHandler,		// IRP_MN_EJECT
		DefaultPnpHandler,		// IRP_MN_SET_LOCK
		DefaultPnpHandler,		// IRP_MN_QUERY_ID
		DefaultPnpHandler,		// IRP_MN_QUERY_PNP_DEVICE_STATE
		DefaultPnpHandler,		// IRP_MN_QUERY_BUS_INFORMATION
		DefaultPnpHandler,		// IRP_MN_DEVICE_USAGE_NOTIFICATION
		DefaultPnpHandler,		// IRP_MN_SURPRISE_REMOVAL
	};

#if DBG
	static char* fcnname[] = 
	{
		"IRP_MN_START_DEVICE",
		"IRP_MN_QUERY_REMOVE_DEVICE",
		"IRP_MN_REMOVE_DEVICE",
		"IRP_MN_CANCEL_REMOVE_DEVICE",
		"IRP_MN_STOP_DEVICE",
		"IRP_MN_QUERY_STOP_DEVICE",
		"IRP_MN_CANCEL_STOP_DEVICE",
		"IRP_MN_QUERY_DEVICE_RELATIONS",
		"IRP_MN_QUERY_INTERFACE",
		"IRP_MN_QUERY_CAPABILITIES",
		"IRP_MN_QUERY_RESOURCES",
		"IRP_MN_QUERY_RESOURCE_REQUIREMENTS",
		"IRP_MN_QUERY_DEVICE_TEXT",
		"IRP_MN_FILTER_RESOURCE_REQUIREMENTS",
		"",
		"IRP_MN_READ_CONFIG",
		"IRP_MN_WRITE_CONFIG",
		"IRP_MN_EJECT",
		"IRP_MN_SET_LOCK",
		"IRP_MN_QUERY_ID",
		"IRP_MN_QUERY_PNP_DEVICE_STATE",
		"IRP_MN_QUERY_BUS_INFORMATION",
		"IRP_MN_DEVICE_USAGE_NOTIFICATION",
		"IRP_MN_SURPRISE_REMOVAL",
	};

	//	KdPrint(("PNP Request (%s)\n", fcnname[fcn]));
#endif // DBG

	NTSTATUS status = STATUS_SUCCESS;
	PDEVICE_EXTENSION pdx;
	PIO_STACK_LOCATION stack;
	ULONG fcn;

	PAGED_CODE();
	KdPrint(("Enter HelloWMDPnp\n"));

	pdx = (PDEVICE_EXTENSION)fdo->DeviceExtension;
	stack = IoGetCurrentIrpStackLocation(Irp);

	fcn = stack->MinorFunction;
	if(fcn >= arraysize(fcntab))
	{
		status = DefaultPnpHandler(pdx,Irp);
		return status;
	}

	status = (*fcntab[fcn])(pdx, Irp);
	KdPrint(("Leave HelloWDMPnp\n"));

	return STATUS_SUCCESS;
}

#pragma PAGEDCODE
NTSTATUS HelloWDMDispatchRoutine( IN PDEVICE_OBJECT fdo, IN PIRP Irp )
{
	PAGED_CODE();
	KdPrint(("Enter HelloWDMDispatchRoutine\n"));

	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	KdPrint(("Leave HelloWDMDispatchRoutine\n"));

	return STATUS_SUCCESS;
}

#pragma PAGEDCODE
void HelloWMDUnload( IN PDRIVER_OBJECT DriverObj )
{
	PAGED_CODE();
	KdPrint(("Enter HelloWMDUnload\n"));
	KdPrint(("Leave HelloWMDUnload\n"));
}
