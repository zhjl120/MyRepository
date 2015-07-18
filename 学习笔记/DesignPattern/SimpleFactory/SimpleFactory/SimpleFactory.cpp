#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "CaseOne.h"
#include "CaseTwo.h"
#include "OperationFactory.h"

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

	switch(cSymblo)
	{
	case '+':
		cout<<"Result: "<<fNum1+fNum2;
		break;
	case  '-':
		cout<<"Result: "<<fNum1-fNum2;
		break;
	case '*':
		cout<<"Result: "<<fNum1*fNum2;
		break;
	case '/':
		cout<<"Result "<<fNum1/fNum2;
		break;
	default:
		break;
	}


	//将界面逻辑与业务逻辑分离

	//Operation oper;
	//cout<<"Result: "<<oper.GetResult(fNum1, fNum2, cSymblo);

	//易维护、易扩展、易复用
	//封装、继承、多态

	OperationFactory factory;
	OperationBase* pOperation = factory.CreateOperation(cSymblo);
	pOperation->SetNum1(fNum1);
	pOperation->SetNum2(fNum2);

	cout<<"Result: "<<pOperation->GetResult();


	cout<<"\r\n";
	system("pause");
	return 0;
}

