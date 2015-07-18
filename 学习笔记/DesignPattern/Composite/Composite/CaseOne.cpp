#include "stdafx.h"
#include "CaseOne.h"


Company::Company( string strName )
{
	m_strName = strName;
}

Company::~Company()
{
}

void Company::Add( Company* c )
{
}

void Company::Remove( Company* c )
{
}

void Company::Display( int nDepth )
{
}

void Company::LineOfDuty()
{
}

ConcreteCompany::ConcreteCompany( string strName ) : Company(strName)
{
}

ConcreteCompany::~ConcreteCompany()
{
}

void ConcreteCompany::Add( Company* c )
{
	m_ChildrenList.push_back(c);
}

void ConcreteCompany::Remove( Company* c )
{
	m_ChildrenList.remove(c);
}

void ConcreteCompany::Display( int nDepth )
{
	for (int nIndex = 0; nIndex < nDepth ; nIndex ++)
		cout<<"-";

	cout<<m_strName<<endl;


	for (list<Company*>::iterator it = m_ChildrenList.begin(); it != m_ChildrenList.end(); it++)
	{
		(*it)->Display(nDepth+2);
	}
}

void ConcreteCompany::LineOfDuty()
{
	for (list<Company*>::iterator it = m_ChildrenList.begin(); it != m_ChildrenList.end(); it++)
	{
		(*it)->LineOfDuty();
	}
}

HRDepartment::HRDepartment( string strName ) : Company(strName)
{
}

HRDepartment::~HRDepartment()
{
}

void HRDepartment::Add( Company* c )
{
}

void HRDepartment::Remove( Company* c )
{
}

void HRDepartment::Display( int nDepth )
{
	for (int nIndex = 0; nIndex < nDepth ; nIndex ++)
		cout<<"-";

	cout<<m_strName<<endl;
}

void HRDepartment::LineOfDuty()
{
	cout<<"职能：员工招聘管理。\n";
}

FinanceDepartment::FinanceDepartment( string strName ) : Company(strName)
{
}

FinanceDepartment::~FinanceDepartment()
{
}

void FinanceDepartment::Add( Company* c )
{
}

void FinanceDepartment::Remove( Company* c )
{
}

void FinanceDepartment::Display( int nDepth )
{
	for (int nIndex = 0; nIndex < nDepth ; nIndex ++)
		cout<<"-";

	cout<<m_strName<<endl;
}

void FinanceDepartment::LineOfDuty()
{
	cout<<"职能：财务收支管理。\n";
}
