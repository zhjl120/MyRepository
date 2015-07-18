// Observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
//#include "Prototype.h"
#include<Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Secretary* sec = new Secretary;

	StockObserver* tongshi1 = new StockObserver("Linda",sec);//观察者名字及观察的对象
	NBAObserver* tongshi2 = new NBAObserver("Dexter",sec);

	sec->Attach(tongshi1);//通知者等级观察者
	sec->Attach(tongshi2);
//	sec->Detach(tongshi2);

	sec->SetSubjectState("boss coming  ");//通知者设置通知的消息

	sec->Notify();//通知所有观察者

	//观察者模式：定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象。这个主题对象
	//在状态发生变化时，会通知所有观察者对象，使他们能够自动更新之间。
	//作用：观察者模式所做的工作其实就是在解除耦合。让耦合的双方都依赖于抽象而不是依赖于具体。
	//           从而使得各自的变化都不会影响另一边的变化。
	//应用：1.当一个对象的改变需要同时改变其他对象。2.当不知道具体有多少对象有待改变时，应该考虑使用观察者模式。
	//------------------------------------------------------


	//ConcreteSubject* pSub = new ConcreteSubject;

	//pSub->Attach(new ConcreteObserver(pSub,"X"));
	//pSub->Attach(new ConcreteObserver(pSub,"Y"));

	//pSub->SetSubjectState("ABC");
	//pSub->Notify();


	cout<<"\n\n";
	system("pause");
	return 0;
}

