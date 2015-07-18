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
	cout<<"T恤  ";
}

void Person::WearBigTrouser()
{
	cout<<"大垮裤  ";
}

void Person::WearSneakers()
{
	cout<<"破球鞋  ";
}

void Person::WearSuit()
{
	cout<<"西装  ";
}

void Person::WearTie()
{
	cout<<"领带  ";
}

void Person::WearLeatherShoes()
{
	cout<<"皮鞋  ";
}

void Person::show()
{
	cout<<m_szName<<"的装扮：";
}

