// FactoryMethod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
#include "CaseTwo.h"
#include "CaseThree.h"
#include <iostream>
#include <windows.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float fNum1 =0 , fNum2 = 0, fResult = 0;
	char cSymblo;

	cout<<"Number1: ";
	cin>>fNum1;

	cout<<"Operation Symblo(+,-,*,/): ";
	cin>>cSymblo;

	cout<<"Number2: ";
	cin>>fNum2;

	//------ 简单工厂实现-----------------------
	OperationFactory factory;
	OperationBase* pOperation = factory.CreateOperation(cSymblo);
	pOperation->SetNum1(fNum1);
	pOperation->SetNum2(fNum2);

	cout<<"\nResult: "<<pOperation->GetResult();

	//工厂方法： 定义一个用于创建对象的接口，让子类决定实例化哪一个类，工厂方法使一个类的实例化延迟到其子类当中。

	//-------工厂方法实现-------------------------
	
	switch(cSymblo)
	{
	case '+':
		OperationFactory2* operFactory =  new AddFactory;
		OperationBase2* oper = operFactory->CreateOperation();
		oper->SetNum1(fNum1);
		oper->SetNum2(fNum2);
		cout<<"\n\nResult: "<<oper->GetResult();
	}


	//----------------------------------------------
	Factory* factory2 = new VolunteerFactory;
	LeiFeng* lei1 = factory2->CreateLeiFeng();
	LeiFeng* lei2 = factory2->CreateLeiFeng();
	LeiFeng* lei3 = factory2->CreateLeiFeng();
	
	lei1->Sweep();
	lei2->Wash();
	lei3->BuyRice();


	cout<<"\n\n";
	system("pause");
	return 0;
}

