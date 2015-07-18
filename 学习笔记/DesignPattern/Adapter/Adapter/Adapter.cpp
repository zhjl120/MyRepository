// Adapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//适配器模式：将一个类的接口转换为客户希望的另外一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
	//适配器模式分为：类适配器模式和对象适配器模式，以下只是对象适配器模式。

	Target* pTarget = new Adapter;
	pTarget->Request();


	cout<<"\n\n";
	//--------------------------------------------

	Player* pPlayer1 = new Forwards("Jack");
	pPlayer1->Attack();

	Player* pPlayer2 = new Guards("Damien");
	pPlayer2->Defense();

	Player* pPlayer3 = new Translator("姚明");
	pPlayer3->Attack();
	pPlayer3->Defense();


	cout<<"\n\n";
	system("pause");
	return 0;
}

