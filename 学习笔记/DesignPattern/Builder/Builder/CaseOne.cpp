#include "stdafx.h"
#include "CaseOne.h"

void PersonThinBuilder::BuildHead()
{
	cout<<"头部 ";
}

void PersonThinBuilder::BuildBody()
{
	cout<<"瘦弱的身体 ";
}

void PersonThinBuilder::BuildArmLeft()
{
	cout<<"左手 ";
}

void PersonThinBuilder::BuildArmRight()
{
	cout<<"右手 ";
}

void PersonThinBuilder::BuildLegLeft()
{
	cout<<"左腿 ";
}

void PersonThinBuilder::BuildLegRight()
{
	cout<<"右腿 ";
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
