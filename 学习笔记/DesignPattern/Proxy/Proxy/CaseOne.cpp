#include "stdafx.h"
#include "CaseOne.h"

SchoolGirl::SchoolGirl( string szName )
{
		m_szName = szName;
}

SchoolGirl::~SchoolGirl()
{
}

std::string SchoolGirl::GetName()
{
	return m_szName;
}



Pursuit::Pursuit( SchoolGirl* mm )
{
	m_mm = mm;
}

Pursuit::~Pursuit()
{
}

void Pursuit::GiveDolls()
{
	cout<<m_mm->GetName()<<":ËÍÄãµÄÑóÍÞÍÞ\n";
}

void Pursuit::GiveFlowers()
{
	cout<<m_mm->GetName()<<":ËÍÄãµÄ»¨\n";
}

void Pursuit::GiveChocolate()
{
	cout<<m_mm->GetName()<<":ËÍÄãµÄÇÉ¿ËÁ¦\n";
}



Proxy2::Proxy2( SchoolGirl* mm )
{
	m_pPursuit = new Pursuit(mm);
}

Proxy2::~Proxy2()
{
}

void Proxy2::GiveDolls()
{
	m_pPursuit->GiveDolls();
}

void Proxy2::GiveFlowers()
{
	m_pPursuit->GiveFlowers();
}

void Proxy2::GiveChocolate()
{
	m_pPursuit->GiveChocolate();
}
