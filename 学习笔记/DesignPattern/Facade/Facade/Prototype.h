#pragma once

#include <iostream>
using namespace std;

class SubSystemOne
{
public:
	void MethodOne();
};

class SubSystemTwo
{
public:
	void MethodTwo();
};

class SubSystemThree
{
public:
	void MethodThree();
};

class SubSystemFour
{
public:
	void MethodFour();
};

class Facade
{
public:
	void MethodA();
	void MethodB();

private:
	SubSystemOne m_SysOne;
	SubSystemTwo m_SysTwo;
	SubSystemThree m_SysThree;
	SubSystemFour m_SysFour;
};