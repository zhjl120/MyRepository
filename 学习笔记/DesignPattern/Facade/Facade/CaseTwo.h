#pragma  once

#include <iostream>
using namespace std;

class Stock4
{
public:
	void Sell();
	void Buy();
};

class Stock5
{
public:
	void Sell();
	void Buy();
};

class Stock6
{
public:
	void Sell();
	void Buy();
};

class NationalDebt2
{
public:
	void Sell();
	void Buy();
};

class Realty2
{
public:
	void Sell();
	void Buy();
};


class Fund
{
public:
	Fund();
	~Fund();

public:
	void SellFund();
	void BuyFund();

private:
	Stock4 m_stock4;
	Stock5 m_stock5;
	Stock6 m_stock6;
	NationalDebt2 m_nd2;
	Realty2 m_rt2;
};