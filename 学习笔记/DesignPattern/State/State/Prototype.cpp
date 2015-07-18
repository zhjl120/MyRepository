#include "stdafx.h"
#include "Prototype.h"

void ConcreteStateA::Handle( C_Context* pContext )
{	
	cout<<"ConcreteStateA: Handle\n";
	pContext->SetState(new ConcreteStateB);
}

void ConcreteStateB::Handle( C_Context* pContext )
{
	cout<<"ConcreteStateB: Handle\n";
	pContext->SetState(new ConcreteStateA);
}

C_Context::C_Context( C_State* pState )
{
	m_pState = pState;
}

C_Context::~C_Context()
{
	if(m_pState !=NULL)
	{		
		delete m_pState;
		m_pState = NULL;
	}
}

C_State* C_Context::GetState()
{
	return m_pState;
}

void C_Context::SetState( C_State* pState )
{
	if(m_pState != NULL)
	{
		delete m_pState;
		m_pState = NULL;
	}
	m_pState = pState;
}

void C_Context::Request()
{
	m_pState->Handle(this);
}

