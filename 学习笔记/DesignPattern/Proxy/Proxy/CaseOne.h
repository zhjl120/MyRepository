#pragma once

#include <string>
#include <iostream>
using namespace std;

class IGiveGift
{
public:
	virtual void GiveDolls() = 0; 
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};


class SchoolGirl
{
public:
	SchoolGirl(string szName);
	~SchoolGirl();

public:
	string GetName();

private:
	string m_szName;
};


class Pursuit : public IGiveGift
{
public:
	Pursuit(SchoolGirl* mm);
	~Pursuit();

public:
	void GiveDolls();
	void GiveFlowers();
	void GiveChocolate();

private:
	SchoolGirl* m_mm;
};


class Proxy2 : public IGiveGift
{
public:
	Proxy2(SchoolGirl* mm);
	~Proxy2();

public:
	void GiveDolls();
	void GiveFlowers();
	void GiveChocolate();

private:
	Pursuit* m_pPursuit;
};