#pragma once

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

class Flyweight
{
public:
	virtual void Operation(int nExtrinsicstate) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
	void Operation(int nExtrinsicstate);
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
	void Operation(int nExtrinsicstate);
};

class FlyweightFactory
{
public:
	FlyweightFactory();
	~FlyweightFactory();

	Flyweight* GetFlyweight(int nKey);

private:
	map<int,ConcreteFlyweight*> m_mapFlyweight;
};