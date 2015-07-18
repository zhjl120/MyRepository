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
		cout<<"等级为："<<nRequest<<", 由Hander1处理\n";
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
		cout<<"等级为："<<nRequest<<", 由Hander2处理\n";
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
		cout<<"等级为："<<nRequest<<", 由Hander3处理\n";
	}
	else
	{
		m_pHander->HandleRequest(nRequest);
	}
}
