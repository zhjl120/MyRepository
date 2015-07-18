// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Singleton::GetInstance()->Test();
	Singleton::GetInstance()->DestroyInstance();


	cout<<"\n\n";
	system("pause");
	return 0;
}

