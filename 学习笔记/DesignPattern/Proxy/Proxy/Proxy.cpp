// Proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Proxy pxy;

	pxy.DoSomething();


//---------CaseOne---------------------
	//����ģʽ��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�
	//�����ౣ��һ������ʹ�ô�����Է���ʵ�壬���ṩһ����ʵ����ͬ�Ľӿڣ���������Ϳ����������ʵ�����ˡ�

	SchoolGirl* mm = new SchoolGirl("jiaojiao");

	Proxy2 pxy2(mm);

	pxy2.GiveDolls();
	pxy2.GiveFlowers();
	pxy2.GiveChocolate();
	

	system("pause");
	return 0;
}

