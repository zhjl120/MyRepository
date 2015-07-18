// AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//抽象工厂：提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
	//好处：1.易于更换产品系列，由于具体工厂类在一个应用中只需在初始化的时候出现一次，这就使得改变一个应用的具体工厂变得容易，
	//              它只需要改变具体工厂即可使用不同的产品配置。
	//            2.它让具体的创建实例过程与客户端分离，客户端是通过它们的抽象接口操纵实例，产品的具体类名也被具体工厂的实现分离，
	//			      不会出现在客户代码中。

	IFactory* factory = new SqlserverFactory;

	IUser* iu = factory->CreateUser();

	iu->GetUser(1);
	iu->Insert("");

	IDepartment* dep = factory->CreateDepartment();

	dep->GetDepartment(1);
	dep->Insert("");

	cout<<"----------------------------------------------\n";
	//-----------------抽象工厂+简单工厂----------

	IUser* iu2 = DataAccess::CreateUser();

	iu2->GetUser(1);
	iu2->Insert("");

	IDepartment* dep2 = DataAccess::CreateDepartment();

	dep2->GetDepartment(1);
	dep2->Insert("");

	system("pause");
	return 0;
}

