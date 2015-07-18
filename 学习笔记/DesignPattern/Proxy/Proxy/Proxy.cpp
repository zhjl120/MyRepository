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
	//代理模式：为其它对象提供一种代理以控制对这个对象的访问。
	//代理类保存一个引用使得代理可以访问实体，并提供一个与实体相同的接口，这样代理就可以用来替代实体类了。

	SchoolGirl* mm = new SchoolGirl("jiaojiao");

	Proxy2 pxy2(mm);

	pxy2.GiveDolls();
	pxy2.GiveFlowers();
	pxy2.GiveChocolate();
	

	system("pause");
	return 0;
}

