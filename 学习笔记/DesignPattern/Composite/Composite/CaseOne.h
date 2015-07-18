#pragma  once

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Company
{
public:
	Company(string strName);
	~Company();

	virtual void Add(Company* c);
	virtual void Remove(Company* c);
	virtual void Display(int nDepth);
	virtual void LineOfDuty();

protected:
	string m_strName;
};

class ConcreteCompany : public Company
{
public:
	ConcreteCompany(string strName);
	~ConcreteCompany();

	void Add(Company* c);
	void Remove(Company* c);
	void Display(int nDepth);
	void LineOfDuty();

private:
	list<Company*> m_ChildrenList;
};

class HRDepartment : public Company
{
public:
	HRDepartment(string strName);
	~HRDepartment();

	void Add(Company* c);
	void Remove(Company* c);
	void Display(int nDepth);
	void LineOfDuty();
};

class FinanceDepartment : public Company
{
public:
	FinanceDepartment(string strName);
	~FinanceDepartment();

	void Add(Company* c);
	void Remove(Company* c);
	void Display(int nDepth);
	void LineOfDuty();
};