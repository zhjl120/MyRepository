#include "stdafx.h"
#include "CaseOne.h"

void PersonThinBuilder::BuildHead()
{
	cout<<"ͷ�� ";
}

void PersonThinBuilder::BuildBody()
{
	cout<<"���������� ";
}

void PersonThinBuilder::BuildArmLeft()
{
	cout<<"���� ";
}

void PersonThinBuilder::BuildArmRight()
{
	cout<<"���� ";
}

void PersonThinBuilder::BuildLegLeft()
{
	cout<<"���� ";
}

void PersonThinBuilder::BuildLegRight()
{
	cout<<"���� ";
}

PersonDirector::PersonDirector( PersonBuilder* pb )
{
	m_pBuilder = pb;
}

void PersonDirector::CreatePerson()
{
	m_pBuilder->BuildHead();
	m_pBuilder->BuildBody();
	m_pBuilder->BuildArmLeft();
	m_pBuilder->BuildArmRight();
	m_pBuilder->BuildLegLeft();
	m_pBuilder->BuildLegRight();
}
