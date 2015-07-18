// Command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//命令模式：将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化，对请求排队或记录请求日志，以及支持可撤销操作。
	//好处：1、它能较容易的设计一个命令队列。 2、在需要的情况下，可以较容易的将命令记入日志。
	//			   3、允许接受请求的一方决定是否要否决请求。4、可以容易的实现对请求的撤销和重做。
	//			   5、由于加进新的具体命令类不影响其他的类，因此增加新的具体命令类很容易。
	//优点：命令模式把请求一个操作的对象与知道怎么执行一个操作的对象分割。

	Receiver r;
	Command* c = new ConcreteCommand(r);
	Invoker i;

	i.SetCommand(c);
	i.ExecuteCommand();

	cout<<"\n----------------------------------------------------------\n";

	Barbecuer boy;
	Command2* pBakeMuttonCmd = new BakeMuttonCommand(boy);
	Command2* pBakeChicken = new BakeChickenWingCommand(boy);
	Waiter girl;

	girl.SetOrder(pBakeChicken);
	girl.SetOrder(pBakeMuttonCmd);
	girl.SetOrder(pBakeChicken);

	girl.Notify();


	cout<<"\n\n";
	system("pause");
	return 0;
}

