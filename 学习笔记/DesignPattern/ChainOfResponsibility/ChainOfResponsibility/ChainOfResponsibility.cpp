// ChainOfResponsibility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//ְ����ģʽ��ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ���������������һ������
	//					     ��������������������ֱ����һ����������Ϊֹ��
	//�ô���1.����ʱ���ӻ��޸Ĵ���һ������Ľṹ����ǿ�˸�����ָ��ְ�������ԡ�
	//			  2.�ܺõĽ���˷�֧�жϵ����⡣

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

