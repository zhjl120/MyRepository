#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include <ntddk.h>
#include <windef.h>
#ifdef __cplusplus
}
#endif

#define PAGEDCODE code_seg("PAGE")
#define LOCKEDCODE code_seg()
#define INITCODE code_seg("INIT")

#define PAGEDDATA data_seg("PAGE")
#define LOCKEDDATA data_seg()
#define INITDATA data_seg("INIT")

#define arraysize(p) (sizeof(p)/sizeof((p)[0]))

typedef struct _DEVICE_EXTENSION{
	PDEVICE_OBJECT pDevice;
	UNICODE_STRING ustrDeviceName;
	UNICODE_STRING ustrSymLinkName;
}DEVICE_EXTENSION,*PDEVICE_EXTENSION;

typedef struct _ServiceDescriptorTbale{
	PVOID ServiceTableBase;//system service dispatch tableµÄ»ùµØÖ·
	PVOID ServiceCounterTable;
	unsigned int NumberOfServices;
	PVOID ParamTableBase;
}*pServiceDesriptorTable;

extern "C" pServiceDesriptorTable KeServiceDescriptorTable; 

typedef struct _JMPCODE{
	BYTE E9;
	ULONG JMPADDR;
}JMPCODE,*PJMPCODE;

NTSTATUS CreateDevice(IN PDRIVER_OBJECT pDriverObject);
VOID HelloDDKUnload(IN PDRIVER_OBJECT pDriverObject);
NTSTATUS HelloDDKDispatchRoutine(IN PDEVICE_OBJECT pDeviceObj , IN PIRP pIrp);

ULONG GetFunctionCurAddrByASM();
ULONG GetFunctionCurAddrByC();

ULONG GetFunctionSrcAddr();