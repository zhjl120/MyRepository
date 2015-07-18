#include "stdafx.h"
#include "CaseOne.h"

void Secretary::Attach( Observer* observer )
{
	m_vecObservers.push_back(observer);
}

void Secretary::Detach( Observer* observer )
{
	vector<Observer*>::iterator it = find(m_vecObservers.begin(), m_vecObservers.end(),observer);
	
	if(it != m_vecObservers.end())
		m_vecObservers.erase(it);
}

void Secretary::Notify()
{
	for (vector<Observer*>::iterator it = m_vecObservers.begin(); it != m_vecObservers.end(); it++)
	{
		(*it)->Update();
	}
}

std::string Secretary::GetSubjectState()
{
	return m_strAction;
}

void Secretary::SetSubjectState( string strSubjectState )
{
	m_strAction = strSubjectState;
}


Observer::Observer( string strName,Subject* pSub )
{
	m_pSubject = pSub;
	m_strName = strName;
}

void Observer::Update()
{
}


StockObserver::StockObserver( string strName ,Subject* pSub) : 
Observer(strName,pSub)
{
}

void StockObserver::Update()
{
	cout<<m_pSubject->GetSubjectState()<<m_strName<<"  快关闭浏览器\n";
}


NBAObserver::NBAObserver( string strName, Subject* pSub ):
Observer(strName, pSub)
{
}

void NBAObserver::Update()
{
	cout<<m_pSubject->GetSubjectState()<<m_strName<<" 快关闭视频\n";
}
