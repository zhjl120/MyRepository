#include "stdafx.h"
#include "Prototype.h"


void SubSystemOne::MethodOne()
{
	cout<<"��ϵͳ����һ\n";
}

void SubSystemTwo::MethodTwo()
{
	cout<<"��ϵͳ������\n";
}


void SubSystemThree::MethodThree()
{
	cout<<"��ϵͳ������\n";
}

void SubSystemFour::MethodFour()
{
	cout<<"��ϵͳ������\n";
}

void Facade::MethodA()
{
	cout<<"������A��\n";
	m_SysOne.MethodOne();
	m_SysTwo.MethodTwo();
	m_SysFour.MethodFour();
}

void Facade::MethodB()
{
	cout<<"������B��\n";
	m_SysTwo.MethodTwo();
	m_SysFour.MethodFour();
}
