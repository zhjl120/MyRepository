// Flyweight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//享元模式：运用共享技术有效的支持大量细粒度的对象。
	//内部状态：在享元对象内部并且不会随环境改变而改变的共享部分。
	//外部状态：随环境改变而改变的、不可以共享的状态。
	//应用：如果一个应用程序使用了大量的对象，而大量的这些对象造成了很大的存储开销时就应该考虑使用。还有就是对象的大多数状态可以是外部状态，
	//		      如果删除对象的外部状态，那么可以用相对较少的共享对象取代多组对象，此时可以考虑使用享元模式。

	int nExtrinsicstate = 10;

	FlyweightFactory f;

	Flyweight* pFlyweight1 = f.GetFlyweight(1);
	pFlyweight1->Operation(nExtrinsicstate++);

	Flyweight* pFlyweight2 = f.GetFlyweight(2);
	pFlyweight1->Operation(nExtrinsicstate++);

	Flyweight* pFlyweight3 = f.GetFlyweight(3);
	pFlyweight1->Operation(nExtrinsicstate++);

	Flyweight* pUnshared = new UnsharedConcreteFlyweight;

	pUnshared->Operation(nExtrinsicstate++);

	//--------------------------------------------------
	cout<<"\n\n";

	WebsitFactory fac;

	WebSit* fx = fac.GetWebSit("产品展示");
	fx->Use(User("zhansan"));

	WebSit* fy = fac.GetWebSit("产品展示");
	fy->Use(User("lisi"));

	WebSit* fz = fac.GetWebSit("产品展示");
	fz->Use(User("wangwu"));

	WebSit* fl = fac.GetWebSit("博客");
	fl->Use(User("zhangtian"));

	WebSit* fm = fac.GetWebSit("博客");
	fm->Use(User("wangliu"));

	WebSit* fn = fac.GetWebSit("博客");
	fn->Use(User("zhangsi"));

	cout<<"对象数："<<fac.GetObjectCount();


	cout<<"\n\n\n";
	system("pause");
	return 0;
}

