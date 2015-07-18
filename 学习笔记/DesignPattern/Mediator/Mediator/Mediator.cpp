// Mediator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//�н���ģʽ����һ���н��������װһϵ�еĶ��󽻻����н���ʹ��������Ҫ��ʾ���໥���ã��Ӷ�ʹ�������ɢ������
	//���Զ����ĸı�����֮��Ľ�����
	//�н���ģʽһ��Ӧ����һ������Զ������õ��Ǹ��ӵķ�ʽ����ͨ�ŵĳ��ϣ��Լ��붨��һ����ֲ��ڶ�����е���Ϊ��
	//���в�������̫�������ĳ��ϡ�

	ConcreteMediator* pMediator = new ConcreteMediator;

	ConcreteColleague1* pColleague1 = new ConcreteColleague1(pMediator);
	ConcreteColleague2* pColleague2 = new ConcreteColleague2(pMediator);

	pMediator->SetColleague1(pColleague1);
	pMediator->SetColleague2(pColleague2);

	pColleague1->Send(1);
	pColleague2->Send(2);


	cout<<"\n\n";
	system("pause");
	return 0;
}

