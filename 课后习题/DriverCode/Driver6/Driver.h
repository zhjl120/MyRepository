#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
#include <ntddk.h>
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

NTSTATUS CreateDevice(IN PDRIVER_OBJECT pDriverObject);
VOID HelloDDKUnload(IN PDRIVER_OBJECT pDriverObject);
NTSTATUS HelloDDKDispatchRoutine(IN PDEVICE_OBJECT pDeviceObj , IN PIRP pIrp);
NTSTATUS MjDeviceContorl(IN PDEVICE_OBJECT pDeviceObj , IN PIRP pIrp);

//-----------------------------------------------------------------------
typedef struct _ServiceDescriptorTbale{
	PVOID ServiceTableBase;//system service dispatch table的基地址
	PVOID ServiceCounterTable;
	unsigned int NumberOfServices;
	PVOID ParamTableBase;
}*pServiceDesriptorTable;

extern "C" pServiceDesriptorTable KeServiceDescriptorTable; 
//获取SSDT结构

typedef NTSTATUS NTOPENPROCESS( 
	__out PHANDLE  ProcessHandle,
	__in ACCESS_MASK  DesiredAccess,
	__in POBJECT_ATTRIBUTES  ObjectAttributes,
	__in_opt PCLIENT_ID  ClientId
	);

NTSTATUS HookNtOpenProcess();

NTSTATUS UnHookNtOpenprocess();

NTSTATUS MyNtOpenProcess(    //Hook NtOpenProcess函数让其先执行我们自己的MyNtOpenProcess函数
	__out PHANDLE  ProcessHandle,
	__in ACCESS_MASK  DesiredAccess,
	__in POBJECT_ATTRIBUTES  ObjectAttributes,
	__in_opt PCLIENT_ID  ClientId
	);


NTOPENPROCESS* pRealNtOpenProcess;//定义一个函数指针，用于存放NtOpenProcess的函数地址
ULONG RealNtOpenProcessAddr;
PEPROCESS EP;
bool bIsHook = false;
HANDLE MyPid;
