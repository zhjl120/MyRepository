// Decorator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "CaseOne.h"
#include "CaseTwo.h"
#include "CaseThree.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{

//------------CaseOne--------------------------------------

	Person zhansan("张三");

	cout<<"第一种装扮:"<<endl;

	zhansan.show();
	zhansan.WearTShirts();
	zhansan.WearBigTrouser();
	zhansan.WearSneakers();

	cout<<"\n\n第二种装扮:"<<endl;

	zhansan.show();
	zhansan.WearSuit();
	zhansan.WearTie();
	zhansan.WearLeatherShoes();



//------------CaseTwo-----------------------------------

	cout<<"\n\n第三种装扮：\n";

	Person2 lisi("李四");
	TShirts tshirt;
	BigTrouser trouser;
	Sneakers sneaker;

	lisi.show();
	tshirt.show();
	trouser.show();
	sneaker.show();

//------------CaseThree-----------------------------------
	//装饰模式：动态的给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活。
	//装饰模式是为已有功能动态地添加更多功能的一种方式。
	//装饰模式把要装饰的功能放在单独的类中，并让这个类包装它所要装饰的对象，因此，当需要执行特殊行为的时候，客户代码就可以在运行
	//时根据有选择地、按顺序地使用装饰功能包装对象了。
	//优点：把类中的装饰功能从类中搬移出去，这样可以简化原来的类。它有效的把类的核心职能和装饰功能区分开了，而且可以去除相关类中
	//重复的装饰逻辑。

	cout<<"\n\n第四种装扮：\n";

	Person3* wangwu = new Person3("王五");
	TShirt3* tshirt3 = new TShirt3;
	BigTrouser3* trouser3 = new BigTrouser3;
	Sneakers3* sneaker3 = new Sneakers3;

	tshirt3->Decorate(wangwu);
	trouser3->Decorate(tshirt3);
	sneaker3->Decorate(trouser3);

	sneaker3->show();


	delete wangwu; delete tshirt3; delete trouser3; delete sneaker3;

	cout<<"\n\n\n";
	system("pause");
	return 0;
}

