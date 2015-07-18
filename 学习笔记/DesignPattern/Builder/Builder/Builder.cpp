// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Director director;
	Builder* b1 = new ConcreteBuilder1;
	
	director.Construct(b1);
	Proudct* p1 = b1->GetResult();
	p1->show();

	delete b1 ; b1 = NULL;
	p1 = NULL;


	cout<<"\n\n";
	//------------------------------------------------------------------
	//建造者模式：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
	//创建者模式的好处是 使得建造代码与表示代码分离，由于建造者隐藏了该产品是如何组装的，所以若需要改变一个产品的内部
	//表示，只需要再定义一个具体的建造者就可以了。
	
	PersonBuilder* pBuilder = new PersonThinBuilder;
	PersonDirector pDir(pBuilder);
	pDir.CreatePerson();

	delete pBuilder; pBuilder = NULL;

	cout<<"\n\n";
	system("pause");
	return 0;
}

