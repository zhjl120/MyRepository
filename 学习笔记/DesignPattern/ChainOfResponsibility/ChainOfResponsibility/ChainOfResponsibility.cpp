// ChainOfResponsibility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//职责链模式：使多个对象都有机会处理请求，从而避免请求的发送者和接受者之间的耦合关系。将这个对象连成一条链，
	//					     并沿着这条链传递请求，直到有一个对象处理它为止。
	//好处：1.可随时增加或修改处理一个请求的结构，增强了给对象指派职责的灵活性。
	//			  2.很好的解决了分支判断的问题。

	Hander* h1 = new ConcreteHander1;
	Hander* h2 = new ConcreteHander2;
	Hander* h3 = new ConcreteHander3;

	h1->SetSuccessor(h2);
	h2->SetSuccessor(h3);

	for (int nIndex = 0; nIndex <10; nIndex++)
	{
		h1->HandleRequest(nIndex);
	}

	cout<<"\n\n";
	system("pause");
	return 0;
}

