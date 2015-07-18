#include "stdafx.h"
#include "Prototype.h"

void Target::Request()
{
	cout<<"普通请求！\n";
}

void Adaptee::SpecificRequest()
{
	cout<<"特殊请求!\n";
}

void Adapter::Request()
{
	m_Adaptee.SpecificRequest();
}
