// Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//桥接模式：将抽象部分与它的实现部分分离，使他们都可以独立变化。
	//这里的实现指的是：抽象类和它的派生类用来实现自己的对象。
	//理解： 实现系统可能有多角度的分类，每一种分类都有可能变化，那么就把这种多角度分离出来让它们独自变化，减少他们之间的耦合。

	Abstraction ab;

	ab.SetImplementor(new ConcreteImplementorA);
	ab.Opeartion();

	ab.SetImplementor(new ConcreteImplementorB);
	ab.Opeartion();


	cout<<"\n\n";
	system("pause");
	return 0;
}

