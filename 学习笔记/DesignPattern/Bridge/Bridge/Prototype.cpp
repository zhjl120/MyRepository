#include "stdafx.h"
#include "Prototype.h"


void ConcreteImplementorA::Operation()
{
	cout<<"����ʵ��A�ķ���ִ��\n";
}

void ConcreteImplementorB::Operation()
{
	cout<<"����ʵ��B�ķ���ִ��\n";
}

Abstraction::Abstraction()
{
	m_pImp = NULL;
}

Abstraction::~Abstraction()
{
	if(m_pImp != NULL)
		delete m_pImp;
}

void Abstraction::SetImplementor( Implementor* pImp )
{
	m_pImp = pImp;
}

void Abstraction::Opeartion()
{
	if(m_pImp != NULL)
		m_pImp->Operation();
}

void RefinedAbstraction::Opeartion()
{
	if(m_pImp != NULL)
		m_pImp->Operation();
}
