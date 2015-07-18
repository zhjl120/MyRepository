// Command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//����ģʽ����һ�������װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������Կͻ����в��������������Ŷӻ��¼������־���Լ�֧�ֿɳ���������
	//�ô���1�����ܽ����׵����һ��������С� 2������Ҫ������£����Խ����׵Ľ����������־��
	//			   3��������������һ�������Ƿ�Ҫ�������4���������׵�ʵ�ֶ�����ĳ�����������
	//			   5�����ڼӽ��µľ��������಻Ӱ���������࣬��������µľ�������������ס�
	//�ŵ㣺����ģʽ������һ�������Ķ�����֪����ôִ��һ�������Ķ���ָ

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

