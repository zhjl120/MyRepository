#include "stdafx.h"
#include "CaseOne.h"

Player::Player( string strName )
{
	m_strName = strName;
}

Player::~Player()
{
}

Forwards::Forwards( string strName ) : Player(strName)
{
}

Forwards::~Forwards()
{
}

void Forwards::Attack()
{
	cout<<"Forwards - "<<m_strName<<" Attack!\n";
}

void Forwards::Defense()
{
	cout<<"Forwards - "<<m_strName<<" Defense!\n";
}

Guards::Guards( string strName ):Player(strName)
{
}

Guards::~Guards()
{
}

void Guards::Attack()
{
	cout<<"Guards - "<<m_strName<<" Attack!\n";
}

void Guards::Defense()
{
	cout<<"Guards - "<<m_strName<<" Defense!\n";
}

ForeignCenter::ForeignCenter()
{
}

ForeignCenter::~ForeignCenter()
{
}

void ForeignCenter::Attack()
{
	cout<<"�⼮�з�-"<<m_strName<<" ����!\n";	
}

void ForeignCenter::Defense()
{
	cout<<"�⼮�з�-"<<m_strName<<" ����!\n";	
}

void ForeignCenter::SetName(string strName)
{
	m_strName = strName;
}

Translator::Translator( string strName ):Player(strName)
{
	m_foreignCenter.SetName(strName);
}

Translator::~Translator()
{
}

void Translator::Attack()
{
	m_foreignCenter.Attack();
}

void Translator::Defense()
{
	m_foreignCenter.Defense();
}


