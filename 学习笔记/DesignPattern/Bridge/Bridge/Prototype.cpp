#include "stdafx.h"
#include "Prototype.h"


void ConcreteImplementorA::Operation()
{
	cout<<"具体实现A的方法执行\n";
}

void ConcreteImplementorB::Operation()
{
	cout<<"具体实现B的方法执行\n";
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
