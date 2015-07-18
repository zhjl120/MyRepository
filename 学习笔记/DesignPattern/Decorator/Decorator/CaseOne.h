#pragma  once

#include <iostream>
#include <string>
using namespace  std;

class Person
{
public:
	Person(string szName);
	~Person();

public:
	void WearTShirts();
	void WearBigTrouser();
	void WearSneakers();
	void WearSuit();
	void WearTie();
	void WearLeatherShoes();
	void show();

private:
	string m_szName;
};