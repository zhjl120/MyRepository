#include "stdafx.h"
#include "Prototype.h"


void SubSystemOne::MethodOne()
{
	cout<<"子系统方法一\n";
}

void SubSystemTwo::MethodTwo()
{
	cout<<"子系统方法二\n";
}


void SubSystemThree::MethodThree()
{
	cout<<"子系统方法三\n";
}

void SubSystemFour::MethodFour()
{
	cout<<"子系统方法四\n";
}

void Facade::MethodA()
{
	cout<<"方法组A：\n";
	m_SysOne.MethodOne();
	m_SysTwo.MethodTwo();
	m_SysFour.MethodFour();
}

void Facade::MethodB()
{
	cout<<"方法组B：\n";
	m_SysTwo.MethodTwo();
	m_SysFour.MethodFour();
}
