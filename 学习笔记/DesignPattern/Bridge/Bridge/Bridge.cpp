// Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//�Ž�ģʽ�������󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����仯��
	//�����ʵ��ָ���ǣ����������������������ʵ���Լ��Ķ���
	//��⣺ ʵ��ϵͳ�����ж�Ƕȵķ��࣬ÿһ�ַ��඼�п��ܱ仯����ô�Ͱ����ֶ�Ƕȷ�����������Ƕ��Ա仯����������֮�����ϡ�

	Abstraction ab;

	ab.SetImplementor(new ConcreteImplementorA);
	ab.Opeartion();

	ab.SetImplementor(new ConcreteImplementorB);
	ab.Opeartion();


	cout<<"\n\n";
	system("pause");
	return 0;
}

