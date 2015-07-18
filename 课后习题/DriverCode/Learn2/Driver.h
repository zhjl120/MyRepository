#ifdef __cplusplus

extern "C"
{
#endif
#include <wdm.h>
#ifdef __cplusplus
};
#endif

typedef struct _DEVICE_EXTENSION{
	PDEVICE_OBJECT fdo;
	PDEVICE_OBJECT NextStackDevice;
	UNICODE_STRING ustrDeviceName;
	UNICODE_STRING ustrSymLinkName;
}DEVICE_EXTENSION,*PDEVICE_EXTENSION;

#define PAGEDCODE code_seg("PAGE")
#define LOCKEDCODE code_seg()
#define INITCODE code_seg("INIT")

#define PAGEDDATA data_seg("PAGE")
#define LOCKEDDATA data_seg()
#define INITDATA data_seg("INIT")

#define arraysize(p) (sizeof(p) / sizeof((p)[0]))

NTSTATUS HelloWDMAddDevice(IN PDRIVER_OBJECT DriverObj, IN PDEVICE_OBJECT PhysicalDeviceObj);
NTSTATUS HelloWDMPnp(IN PDEVICE_OBJECT fdo, IN PIRP Irp);
NTSTATUS HelloWDMDispatchRoutine(IN PDEVICE_OBJECT fdo, IN PIRP Irp);
void HelloWMDUnload(IN PDRIVER_OBJECT DriverObj);
NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObj, IN PUNICODE_STRING RegistryPath);






