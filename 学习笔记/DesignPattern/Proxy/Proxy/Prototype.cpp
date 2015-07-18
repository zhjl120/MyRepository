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
	cout<<"Real Object: Do Something\n";//本应该做的任务
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

	m_realSubject->DoSomething();//通过代理模式，调用原始对象的功能。
}
