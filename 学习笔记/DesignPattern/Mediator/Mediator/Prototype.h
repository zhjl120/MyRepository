#pragma  once

#include <iostream>
using namespace std;

class Colleague;

class Mediator
{
public:
	virtual void Send(int nMessageId, Colleague* pColleague) = 0;
};

class Colleague 
{
public:
	Colleague(Mediator* pMediator);
	virtual void Send(int nMessageId);

protected:
	Mediator* m_pMediator;
};

class ConcreteColleague1 : public Colleague
{
public:
	ConcreteColleague1(Mediator* p);
	void Notify(int nMessageId);
};

class ConcreteColleague2 : public Colleague
{
public:
	ConcreteColleague2(Mediator* p);
	void Notify(int nMessageId);
};


class ConcreteMediator : public Mediator
{
public:
	void Send(int nMessageId, Colleague* pColleague);
	void SetColleague1(ConcreteColleague1* pColleague);
	void SetColleague2(ConcreteColleague2* pColleague);

private:
	ConcreteColleague1* m_pColleague1;
	ConcreteColleague2* m_pColleague2;
};