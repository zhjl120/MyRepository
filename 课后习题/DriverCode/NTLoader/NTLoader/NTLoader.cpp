// NTLoader.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>

#define DRIVER_NAME "Learn1.sys"
#define DRIVER_PATH "C:\\WrokSpace\\Learn1\\WinDDK"

BOOL LoadNTDriver(char* lpszDriverName, char* lpszDriverPath);
BOOL UnloadNTDriver(char* szSvrName);

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL bRet = LoadNTDriver(DRIVER_NAME,DRIVER_PATH);
	if (!bRet)
	{
		printf("LoadNTDriver() faild !\n");
		system("pause");
		return 0;
	}

	printf("press any key to unload the driver\n");
	getch();

	bRet = UnloadNTDriver(DRIVER_NAME);
	if (!bRet)
	{
		printf("UnloadNTDriver() faild! \n");
		system("pause");
		return 0;
	}

	system("pause");

	return 0;
}

BOOL LoadNTDriver( char* lpszDriverName, char* lpszDriverPath )
{
	char szDriverImagePath[256];
	BOOL bRet = FALSE;

	GetFullPathName(lpszDriverPath,256, szDriverImagePath, NULL);

	SC_HANDLE hServiceMgr = NULL;
	SC_HANDLE hServiceDDK = NULL;

	hServiceMgr = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if(hServiceMgr == NULL)
	{
		printf("OpenSCManager() Faild %d !\n",GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	else
	{
		printf("OpenSCManager() Ok ! \n");
	}

	hServiceDDK = CreateService(hServiceMgr, lpszDriverName ,lpszDriverName, SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER,
								SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, szDriverImagePath,NULL,NULL,NULL,NULL,NULL);
	DWORD dwRet;

	if(hServiceDDK == NULL)
	{
		dwRet = GetLastError();

		if(dwRet != ERROR_IO_PENDING && dwRet != ERROR_SERVICE_EXISTS)
		{
			printf("CreateService() Faild %d !\n",GetLastError());
			bRet = FALSE;
			goto BeforeLeave;
		}
		else
		{
			printf("Service is already created!\n");
		}

		hServiceDDK = OpenService(hServiceMgr, lpszDriverName, SERVICE_ALL_ACCESS);

		if(hServiceDDK == NULL)
		{
			dwRet = GetLastError();
			printf("OpenService() faild %d !\n",dwRet);
			bRet = FALSE;
			goto BeforeLeave;
		}
		else
		{
			printf("OpenService success!\n");
		}
	}
	else
	{
		printf("CreateService success !\n");
	}

	bRet = StartService(hServiceDDK, NULL, NULL);

	if (!bRet)
	{
		DWORD dwRtn = GetLastError();
		if (dwRtn != ERROR_IO_PENDING && dwRtn != ERROR_SERVICE_ALREADY_RUNNING)
		{
			printf("StartService() faild %d !\n",GetLastError());
			bRet = FALSE;
			goto BeforeLeave;
		}
		else
		{
			if(dwRtn == ERROR_IO_PENDING)
			{
				printf("StartService() Faild ERROR_IO_PENDING!\n");
				bRet = FALSE;
				goto BeforeLeave;
			}
			else
			{
				printf("StartService() faild ERROR_IO_ALREADY_RUNNING!\n");
				bRet = TRUE;
				goto BeforeLeave;
			}
		}

	}
	bRet = TRUE;

BeforeLeave:
	if (hServiceDDK)
	{
		CloseServiceHandle(hServiceDDK);
	}

	if (hServiceMgr)
	{
		CloseServiceHandle(hServiceMgr);
	}

	return bRet;
}

BOOL UnloadNTDriver( char* szSvrName )
{
	BOOL bRet = FALSE;
	SC_HANDLE hServiceMgr = NULL;
	SC_HANDLE hServiceDDK = NULL;
	SERVICE_STATUS SvrSta;

	hServiceMgr = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);

	if (hServiceMgr == NULL)
	{
		printf("OpenSCManager() Faild %d !\n",GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	else
		printf("OpenSCManager() success !\n");

	hServiceDDK = OpenService(hServiceMgr,szSvrName, SERVICE_ALL_ACCESS);

	if(hServiceDDK == NULL)
	{
		printf("OpenService() faild %d !\n",GetLastError());
		bRet = FALSE;
		goto BeforeLeave;
	}
	else
		printf("OpenService success !\n");

	if(! ControlService(hServiceDDK,SERVICE_CONTROL_STOP,&SvrSta))
	{
		printf("ControlService() faild %d !\n",GetLastError());
	}
	else
	{
		printf("ControlService() success !\n");
	}

	if(! DeleteService(hServiceDDK))
	{
		printf("DeleteService() faild %d\n",GetLastError());
	}
	else
	{
		printf("DeleteService() success !\n");
	}

	bRet = TRUE;
BeforeLeave:
	if (hServiceDDK)
	{
		CloseServiceHandle(hServiceDDK);
	}
	if (hServiceMgr)
	{
		CloseServiceHandle(hServiceMgr);
	}

	return bRet;
}

void TestDriver()
{
	HANDLE hDevice = CreateFile("\\\\.\\HelloDDK",GENERIC_WRITE | GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);

	if(hDevice != INVALID_HANDLE_VALUE)
		printf("Open Driver Success!\n");
	else
		printf("Open Driver faild %d !\n",GetLastError());
	
	CloseHandle(hDevice);
}