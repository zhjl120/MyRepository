#include "stdafx.h"
#include "Prototype.h"


Colleague::Colleague( Mediator* pMediator )
{
	m_pMediator = pMediator;
}

void Colleague::Send( int nMessageId )
{
	m_pMediator->Send(nMessageId, this);
}

ConcreteColleague1::ConcreteColleague1( Mediator* p ) : Colleague(p)
{
}

void ConcreteColleague1::Notify( int nMessageId )
{
	cout<<"同事1收到通知\n";
}

ConcreteColleague2::ConcreteColleague2( Mediator* p ) : Colleague(p)
{
}

void ConcreteColleague2::Notify( int nMessageId )
{
	cout<<"同事2收到通知\n";
}


void ConcreteMediator::Send( int nMessageId, Colleague* pColleague )
{
	ConcreteColleague1* pColleague1 = dynamic_cast<ConcreteColleague1*> (pColleague);
	ConcreteColleague2* pColleague2 = dynamic_cast<ConcreteColleague2*> (pColleague);

	if (pColleague1 != NULL)
	{
		m_pColleague1->Notify(nMessageId);
	}
	else if(pColleague2 != NULL)
	{
		m_pColleague2->Notify(nMessageId);
	}

}

void ConcreteMediator::SetColleague1( ConcreteColleague1* pColleague )
{
	m_pColleague1 = pColleague;
}

void ConcreteMediator::SetColleague2( ConcreteColleague2* pColleague )
{
	m_pColleague2  = pColleague;
}