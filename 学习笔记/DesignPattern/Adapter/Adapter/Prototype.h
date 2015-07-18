#pragma  once

#include <iostream>
using namespace std;

class Target
{
public:
	virtual void Request();
};

class Adaptee
{
public:
	void SpecificRequest();
};

class Adapter : public Target
{
public:
	void Request();

private:
	Adaptee m_Adaptee;
};