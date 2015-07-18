#pragma  once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Observer;

class Subject{  //֪ͨ�߳�����
public:
	 virtual void Attach(Observer* observer) = 0;  //�Ǽ�һ��֪ͨ����
	 virtual void Detach(Observer* observer) = 0;//�Ƴ�һ��֪ͨ����
	 virtual void Notify() = 0;//֪ͨ���еǼǹ��Ķ���

	virtual string GetSubjectState() = 0; //��ȡ������֪ͨ����
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
	vector<Observer*> m_vecObservers;//���ڴ����Ҫ֪ͨ�Ķ���
	string m_strAction;
};


class Observer{   //�۲��߳�����
public:
	Observer(string strName, Subject* pSub); //��Ҫ��һ���۲��ߵ����֣��͹۲�Ķ���
	virtual void Update();

protected:
	string m_strName;
	Subject* m_pSubject;  //�۲�Ķ��󣬼����ö����б仯ʱ��֪ͨ����
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