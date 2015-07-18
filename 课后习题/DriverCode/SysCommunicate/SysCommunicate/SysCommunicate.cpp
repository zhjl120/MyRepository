// SysCommunicate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <winioctl.h>

//#define add_code CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS) 
//#define add_code CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_IN_DIRECT, FILE_ANY_ACCESS) 
//#define add_code CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS) 
//METHOD_BUFFERED:表示使用缓冲区访问模式
//METHOD_IN_DIRECT：表示使用直接访问模式
//METHOD_NEITHER:表示使用其它访问模式
//如果使用不同驱动程序，这里需要注意修改

#define HOOK_CODE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS) 
#define UNHOOK_CODE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS) 

//int add(int nNum1, int nNum2)
//{
//	int nInBuffer[2];
//	int nOutBuffer;
//	DWORD dwWirte;
//
//	nInBuffer[0] = nNum1;
//	nInBuffer[1] = nNum2;
//
//	HANDLE hDevice = CreateFile(L"\\\\.\\YouCaiHua",
//		GENERIC_READ | GENERIC_WRITE,
//		0,
//		NULL,
//		OPEN_EXISTING,
//		FILE_ATTRIBUTE_NORMAL,
//		NULL);
//
//	if (hDevice == INVALID_HANDLE_VALUE)
//	{
//		printf("hDevice faild !\r\n");
//		return 0;
//	}
//
//	DeviceIoControl(hDevice, add_code, &nInBuffer, sizeof(nInBuffer), &nOutBuffer, sizeof(nOutBuffer),
//					&dwWirte, NULL);
//
//	return nOutBuffer;
//}

void HookNtOpenProcess(ULONG pId)
{
	int nInBuffer[2];
	int nOutBuffer;
	DWORD dwWirte;

	nInBuffer[0] = pId;

	HANDLE hDevice = CreateFile(L"\\\\.\\YouCaiHua",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hDevice == INVALID_HANDLE_VALUE)
	{
		printf("hDevice faild !\r\n");
		return ;
	}

	DeviceIoControl(hDevice, HOOK_CODE, &nInBuffer, sizeof(nInBuffer), &nOutBuffer, sizeof(nOutBuffer),
		&dwWirte, NULL);

}

void UnHookNtOpenProcess()
{
	int nInBuffer[2];
	int nOutBuffer;
	DWORD dwWirte;


	HANDLE hDevice = CreateFile(L"\\\\.\\YouCaiHua",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hDevice == INVALID_HANDLE_VALUE)
	{
		printf("hDevice faild !\r\n");
		return ;
	}

	DeviceIoControl(hDevice, UNHOOK_CODE, &nInBuffer, sizeof(nInBuffer), &nOutBuffer, sizeof(nOutBuffer),
		&dwWirte, NULL);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//int nResult;


	//int nNum1 = 1111, nNum2 = 2222;

	//nResult = add(nNum1, nNum2);

	//printf("%d + %d = %d\n",nNum1, nNum2, nResult);

	ULONG pId;

	HookNtOpenProcess(404);
	//UnHookNtOpenProcess();

	system("pause");
	return 0;
}

