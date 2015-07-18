// Facade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
#include "CaseTwo.h"
#include "Prototype.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Stock1 gu1;
	Stock2 gu2;
	Stock3 gu3;
	NationalDebt1 nd1;
	Realty1 rt1;

	gu1.Buy();
	gu2.Buy();
	gu3.Buy();
	nd1.Buy();
	rt1.Buy();

	gu1.Sell();
	gu2.Sell();
	gu3.Sell();
	nd1.Sell();
	rt1.Sell();

	cout<<"---------------------------------------------\n";
	
	//���ģʽ��Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һֱ�Ľ��棬��ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á�


	Fund jijin;
	jijin.BuyFund();
	jijin.SellFund();

	cout<<"---------------------------------------------\n";

	Facade fd;
	fd.MethodA();
	cout<<"\n";
	fd.MethodB();


	cout<<"\n\n\n";
	system("pause");
	return 0;
}

