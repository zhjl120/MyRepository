#pragma  once
#include <iostream>
#include <string>
using namespace std;

class Person2
{
public:
	Person2(string szName);
	~Person2();

public:
	void show();

private:
	string m_szName;
};

//--------◊∞ Œ¿‡ -------------------------

class Finery
{
public:
	void show();
};

class TShirts : public Finery
{
public:
	void show();
};

class BigTrouser : public Finery
{
public:
	void show();
};

class Sneakers : public Finery
{
public:
	void show();
};

class Suit : public Finery
{
public:
	void show();
};