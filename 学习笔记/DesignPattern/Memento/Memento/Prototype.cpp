#include "stdafx.h"
#include "Prototype.h"

Memento* Originator::CreateMemento()
{
	return new Memento(m_strState);
}

void Originator::SetMemento( Memento* m )
{
	m_strState = m->GetState();
}

void Originator::Show()
{
	cout<<"Current State: "<<m_strState<<"\n";
}

void Originator::SetState( string strState )
{
	m_strState = strState;
}

std::string Originator::GetState()
{
	return m_strState;
}


Memento::Memento( string strState )
{
	m_strState = strState;
}

Memento::~Memento()
{
}

std::string Memento::GetState()
{
	return m_strState;
}

Caretaker::Caretaker()
{
	m_pMemento = NULL;
}

Caretaker::~Caretaker()
{
	if(m_pMemento != NULL)
	{
		delete m_pMemento;
		m_pMemento = NULL;
	}
}

Memento* Caretaker::GetMemento()
{
	return m_pMemento;
}

void Caretaker::SetMemento( Memento* m )
{
	m_pMemento = m;
}

