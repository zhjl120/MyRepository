#pragma  once

#include <iostream>
using namespace std;

class Implementor
{
public:
	virtual void Operation() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
	void Operation();
};

class ConcreteImplementorB : public Implementor
{
public:
	void Operation();
};


class Abstraction
{
public:
	Abstraction();
	~Abstraction();

	void SetImplementor(Implementor* pImp);
	virtual void Opeartion();

protected:
	Implementor* m_pImp;
};

class RefinedAbstraction : public Abstraction
{
public:
	void Opeartion();
};