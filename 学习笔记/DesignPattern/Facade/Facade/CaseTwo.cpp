#include "stdafx.h"
#include "CaseTwo.h"

void Stock4::Sell()
{
	cout<<"���۹�Ʊ4\n";
}

void Stock4::Buy()
{
	cout<<"�����Ʊ4\n";
}


void Stock5::Sell()
{
	cout<<"���۹�Ʊ5\n";
}

void Stock5::Buy()
{
	cout<<"�����Ʊ5\n";
}

void Stock6::Sell()
{
	cout<<"���۹�Ʊ6\n";
}

void Stock6::Buy()
{
	cout<<"�����Ʊ6\n";
}

void NationalDebt2::Sell()
{
	cout<<"���۹�ծ2\n";
}

void NationalDebt2::Buy()
{
	cout<<"�����ծ2\n";
}

void Realty2::Sell()
{
	cout<<"���۷���2\n";
}

void Realty2::Buy()
{
	cout<<"���뷿��2\n";
}


Fund::Fund()
{
}

Fund::~Fund()
{
}

void Fund::SellFund()
{
	m_stock4.Sell();
	m_stock5.Sell();
	m_stock6.Sell();
	m_nd2.Sell();
	m_rt2.Sell();
}

void Fund::BuyFund()
{
	m_stock4.Buy();
	m_stock5.Buy();
	m_stock6.Buy();
	m_nd2.Buy();
	m_rt2.Buy();
}
