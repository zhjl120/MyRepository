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
	cout<<m_szName<<"��װ�磺";
}



//---------------װ�����------------------------
void Finery::show()
{
}

//---------------װ��ʵ����------------------------
void TShirts::show()
{
	cout<<"T��  ";
}

void BigTrouser::show()
{
	cout<<"����  ";
}

void Sneakers::show()
{
	cout<<"����Ь  ";
}

void Suit::show()
{
	cout<<"��װ  ";
}
