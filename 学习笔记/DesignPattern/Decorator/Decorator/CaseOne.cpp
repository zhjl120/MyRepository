#include "stdafx.h"
#include "CaseOne.h"

Person::Person( string szName )
{
	m_szName= szName;
}

Person::~Person()
{
}

void Person::WearTShirts()
{
	cout<<"T��  ";
}

void Person::WearBigTrouser()
{
	cout<<"����  ";
}

void Person::WearSneakers()
{
	cout<<"����Ь  ";
}

void Person::WearSuit()
{
	cout<<"��װ  ";
}

void Person::WearTie()
{
	cout<<"���  ";
}

void Person::WearLeatherShoes()
{
	cout<<"ƤЬ  ";
}

void Person::show()
{
	cout<<m_szName<<"��װ�磺";
}

