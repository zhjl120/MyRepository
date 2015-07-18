#pragma once

#include <iostream>
using namespace std;

class Subject//公共接口
{
public:
	virtual void DoSomething() = 0;
};

class RealSubject : public Subject //真实实现类
{
public:
	RealSubject();
	~RealSubject();

public:
	void DoSomething();
};

class Proxy : public Subject //代理类
{
public:
	Proxy();
	~Proxy();

public:
	void DoSomething();

private:
	RealSubject* m_realSubject;//保持一个真实实现类对象，用于实现原始功能
};