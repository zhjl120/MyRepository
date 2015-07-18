#include "stdafx.h"
#include "Prototype.h"

void Subject::Attach(Observer* ob)
{
	m_vecObservers.push_back(ob);
}

void Subject::Detach(Observer* ob)
{
	vector<Observer*>::iterator it = find(m_vecObservers.begin(), m_vecObservers.end(),ob);

	if(it != m_vecObservers.end())
		m_vecObservers.erase(it);
}

void Subject::Notify()
{
	for (vector<Observer*>::iterator it = m_vecObservers.begin(); it != m_vecObservers.end(); it++)
	{
		(*it)->Update();
	}
}

void Subject::SetSubjectState( string strState )
{
	m_strState = strState;
}

std::string Subject::GetSubjectState()
{
	return m_strState;
}


ConcreteObserver::ConcreteObserver( ConcreteSubject* subject, string strName )
{
	m_strName = strName;
	m_pSubject = subject;
}

void ConcreteObserver::Update()
{
	m_strState = m_pSubject->GetSubjectState();
	cout<<m_strName<<" "<<m_strState<<endl;
}
