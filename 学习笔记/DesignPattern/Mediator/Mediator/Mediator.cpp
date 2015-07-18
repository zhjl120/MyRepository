// Mediator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//中介者模式：用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显示的相互引用，从而使其耦合松散，而且
	//可以独立的改变它们之间的交互。
	//中介者模式一般应用于一组对象以定义良好但是复杂的方式进行通信的场合，以及想定制一个想分布在多个类中的行为，
	//而有不想生成太多的子类的场合。

	ConcreteMediator* pMediator = new ConcreteMediator;

	ConcreteColleague1* pColleague1 = new ConcreteColleague1(pMediator);
	ConcreteColleague2* pColleague2 = new ConcreteColleague2(pMediator);

	pMediator->SetColleague1(pColleague1);
	pMediator->SetColleague2(pColleague2);

	pColleague1->Send(1);
	pColleague2->Send(2);


	cout<<"\n\n";
	system("pause");
	return 0;
}

