#include "stdafx.h"
#include "CaseOne.h"

int GameRole::GetVit()
{
	return m_nVit;
}

int GameRole::GetAtk()
{
	return m_nAtk;
}

int GameRole::GetDef()
{
	return m_nDef;
}

void GameRole::SetVit( int nVit )
{
	m_nVit = nVit;
}

void GameRole::SetAtk( int nAtk )
{
	m_nAtk = nAtk;
}

void GameRole::SetDef( int nDef )
{
	m_nDef = nDef;
}

void GameRole::StateDisplay()
{
	cout<<"Vit: "<<m_nVit<<", Atk: "<<m_nAtk<<", Def: "<<m_nDef<<"\n";
}

void GameRole::GetInitState()
{
	m_nAtk  = 100;
	m_nDef = 100;
	m_nVit = 100;
}

void GameRole::Fight()
{
	m_nAtk  = 0;
	m_nDef = 0;
	m_nVit = 0;
}

RoleStateMemento* GameRole::SaveState()
{
	return new RoleStateMemento(m_nAtk, m_nVit, m_nDef);
}

void GameRole::RecoveryState( RoleStateMemento* m )
{
	m_nAtk = m->GetAtk();
	m_nVit = m->GetVit();
	m_nDef = m->GetDef();
}


RoleStateMemento::RoleStateMemento( int nVit, int nAtk, int nDef )
{
	m_nAtk = nAtk;
	m_nDef = nDef;
	m_nVit = nVit;
}

RoleStateMemento::~RoleStateMemento()
{
}

int RoleStateMemento::GetVit()
{
	return m_nVit;
}

int RoleStateMemento::GetAtk()
{
	return m_nAtk;
}

int RoleStateMemento::GetDef()
{
	return m_nDef;
}


RoleStateCaretaker::RoleStateCaretaker()
{
	m_pMemento = NULL;
}

RoleStateCaretaker::~RoleStateCaretaker()
{
	if (m_pMemento !=  NULL)
	{
		delete m_pMemento;
		m_pMemento = NULL;
	}
}

RoleStateMemento* RoleStateCaretaker::GetMemento()
{
	return m_pMemento;
}

void RoleStateCaretaker::SetMemento( RoleStateMemento* m )
{
	m_pMemento = m;
}

