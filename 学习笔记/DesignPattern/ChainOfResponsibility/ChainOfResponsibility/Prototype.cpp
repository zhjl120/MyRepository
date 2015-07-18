#include "stdafx.h"
#include "Prototype.h"


void Hander::SetSuccessor( Hander* pHander )
{
	m_pHander = pHander;
}

void ConcreteHander1::HandleRequest( int nRequest )
{
	if (nRequest < 3)
	{
		cout<<"�ȼ�Ϊ��"<<nRequest<<", ��Hander1����\n";
	}
	else
	{
		m_pHander->HandleRequest(nRequest);
	}
}

void ConcreteHander2::HandleRequest( int nRequest )
{
	if (nRequest < 6)
	{
		cout<<"�ȼ�Ϊ��"<<nRequest<<", ��Hander2����\n";
	}
	else
	{
		m_pHander->HandleRequest(nRequest);
	}
}

void ConcreteHander3::HandleRequest( int nRequest )
{
	if (nRequest < 10)
	{
		cout<<"�ȼ�Ϊ��"<<nRequest<<", ��Hander3����\n";
	}
	else
	{
		m_pHander->HandleRequest(nRequest);
	}
}
