#pragma  once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Observer;

class Subject{  //通知者抽象类
public:
	 virtual void Attach(Observer* observer) = 0;  //登记一个通知对象
	 virtual void Detach(Observer* observer) = 0;//移除一个通知对象
	 virtual void Notify() = 0;//通知所有登记过的对象

	virtual string GetSubjectState() = 0; //获取和设置通知内容
	virtual void SetSubjectState(string strSubjectState) = 0;
};


class Secretary :public Subject{
public:
	void Attach(Observer* observer);
	void Detach(Observer* observer);
	void Notify();
	
	string GetSubjectState();
	void SetSubjectState(string strSubjectState);

private:
	vector<Observer*> m_vecObservers;//用于存放需要通知的对象
	string m_strAction;
};


class Observer{   //观察者抽象类
public:
	Observer(string strName, Subject* pSub); //需要有一个观察者的名字，和观察的对象
	virtual void Update();

protected:
	string m_strName;
	Subject* m_pSubject;  //观察的对象，即当该对象有变化时回通知自身。
};


class StockObserver : public Observer
{
public:
	StockObserver(string strName,Subject* pSub);
	void Update();
};

class NBAObserver : public Observer
{
public:
	NBAObserver(string strName, Subject* pSub);
	void Update();
};