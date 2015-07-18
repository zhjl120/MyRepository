#pragma once

#include <iostream>
using namespace std;

class Subject//�����ӿ�
{
public:
	virtual void DoSomething() = 0;
};

class RealSubject : public Subject //��ʵʵ����
{
public:
	RealSubject();
	~RealSubject();

public:
	void DoSomething();
};

class Proxy : public Subject //������
{
public:
	Proxy();
	~Proxy();

public:
	void DoSomething();

private:
	RealSubject* m_realSubject;//����һ����ʵʵ�����������ʵ��ԭʼ����
};