#pragma once

#include <iostream>
using namespace std;

class Hander
{
public:
	void SetSuccessor(Hander* pHander);
	virtual void HandleRequest(int nRequest) = 0;

protected:
	Hander* m_pHander;
};

class ConcreteHander1 : public Hander
{
public:
	void HandleRequest(int nRequest);
};

class ConcreteHander2 : public Hander
{
public:
	void HandleRequest(int nRequest);
};

class ConcreteHander3 : public Hander
{
public:
	void HandleRequest(int nRequest);
};
