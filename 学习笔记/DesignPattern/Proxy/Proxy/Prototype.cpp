#include "stdafx.h"
#include "Prototype.h"

RealSubject::RealSubject()
{
}

RealSubject::~RealSubject()
{
}

void RealSubject::DoSomething()
{
	cout<<"Real Object: Do Something\n";//��Ӧ����������
}


Proxy::Proxy()
{
	m_realSubject = NULL;
}

Proxy::~Proxy()
{
}

void Proxy::DoSomething()
{
	if (m_realSubject == NULL)
	{
		m_realSubject = new RealSubject;
	}

	m_realSubject->DoSomething();//ͨ������ģʽ������ԭʼ����Ĺ��ܡ�
}
