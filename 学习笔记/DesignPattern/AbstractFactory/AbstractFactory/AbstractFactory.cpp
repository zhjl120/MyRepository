// AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//���󹤳����ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ
	//�ô���1.���ڸ�����Ʒϵ�У����ھ��幤������һ��Ӧ����ֻ���ڳ�ʼ����ʱ�����һ�Σ����ʹ�øı�һ��Ӧ�õľ��幤��������ף�
	//              ��ֻ��Ҫ�ı���幤������ʹ�ò�ͬ�Ĳ�Ʒ���á�
	//            2.���þ���Ĵ���ʵ��������ͻ��˷��룬�ͻ�����ͨ�����ǵĳ���ӿڲ���ʵ������Ʒ�ľ�������Ҳ�����幤����ʵ�ַ��룬
	//			      ��������ڿͻ������С�

	IFactory* factory = new SqlserverFactory;

	IUser* iu = factory->CreateUser();

	iu->GetUser(1);
	iu->Insert("");

	IDepartment* dep = factory->CreateDepartment();

	dep->GetDepartment(1);
	dep->Insert("");

	cout<<"----------------------------------------------\n";
	//-----------------���󹤳�+�򵥹���----------

	IUser* iu2 = DataAccess::CreateUser();

	iu2->GetUser(1);
	iu2->Insert("");

	IDepartment* dep2 = DataAccess::CreateDepartment();

	dep2->GetDepartment(1);
	dep2->Insert("");

	system("pause");
	return 0;
}

