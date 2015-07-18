#pragma  once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Observer;

class Subject{
public:
	virtual void Attach(Observer* ob);
	virtual void Detach(Observer* ob);
	virtual void Notify();
	virtual void SetSubjectState(string strState);
	virtual string GetSubjectState();

private:
	vector<Observer*> m_vecObservers;
	string m_strState;
};


class ConcreteSubject : public Subject
{
};


class Observer{
public:
	virtual void Update() = 0;
};

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(ConcreteSubject* subject, string strName);
	
	void Update();

private:
	string m_strName;
	string m_strState;
	Subject* m_pSubject;
};