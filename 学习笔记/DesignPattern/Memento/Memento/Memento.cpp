// Memento.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//备忘录模式：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。
	//						 这样以后就可以将对象恢复到原先保存的状态。

	//备忘录模式比较适合于功能比较复杂的，但需要维护或记录属性历史的类，或者需要保存的属性只是众多属性中的一小部分时，
	//Originator可以根据保存的Memento信息还原到前一状态。

	Originator o;
	o.SetState("On");
	o.Show();

	Caretaker c;
	c.SetMemento(o.CreateMemento());

	o.SetState("Off");
	o.Show();

	o.SetMemento(c.GetMemento());
	o.Show();

	cout<<"\n\n";
	//---------------------------------------------------------------

	GameRole player;
	player.GetInitState();
	player.StateDisplay();

	RoleStateCaretaker stateAdmin;
	stateAdmin.SetMemento(player.SaveState());

	player.Fight();
	player.StateDisplay();

	player.RecoveryState(stateAdmin.GetMemento());
	player.StateDisplay();


	cout<<"\n\n";
	system("pause");
	return 0;
}

