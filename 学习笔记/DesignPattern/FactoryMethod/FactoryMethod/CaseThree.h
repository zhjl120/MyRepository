#pragma  once

#include <iostream>
using namespace std;

class LeiFeng
{
public:
	virtual void Sweep();
	virtual void Wash();
	virtual void BuyRice();
};

class Undergraduate : public LeiFeng
{
public:
	void Sweep();
	void Wash();
	void BuyRice();
};


class Volunteer : public LeiFeng
{
public:
	void Sweep();
	void Wash();
	void BuyRice();
};



class Factory 
{
public:
	 virtual LeiFeng* CreateLeiFeng();
};

class UndergraduateFactory : public Factory
{
public:
	LeiFeng* CreateLeiFeng();
};

class VolunteerFactory : public Factory
{
public:
	LeiFeng* CreateLeiFeng();
};