// Memento.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//����¼ģʽ���ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��
	//						 �����Ժ�Ϳ��Խ�����ָ���ԭ�ȱ����״̬��

	//����¼ģʽ�Ƚ��ʺ��ڹ��ܱȽϸ��ӵģ�����Ҫά�����¼������ʷ���࣬������Ҫ���������ֻ���ڶ������е�һС����ʱ��
	//Originator���Ը��ݱ����Memento��Ϣ��ԭ��ǰһ״̬��

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

