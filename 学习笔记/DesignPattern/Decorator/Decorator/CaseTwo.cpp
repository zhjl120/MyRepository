#include "stdafx.h"
#include "CaseTwo.h"

Person2::Person2( string szName )
{
	m_szName = szName;
}

Person2::~Person2()
{
}

void Person2::show()
{
	cout<<m_szName<<"的装扮：";
}



//---------------装扮基类------------------------
void Finery::show()
{
}

//---------------装扮实现类------------------------
void TShirts::show()
{
	cout<<"T恤  ";
}

void BigTrouser::show()
{
	cout<<"大垮裤  ";
}

void Sneakers::show()
{
	cout<<"破球鞋  ";
}

void Suit::show()
{
	cout<<"西装  ";
}
