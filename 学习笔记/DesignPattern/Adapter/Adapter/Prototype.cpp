#include "stdafx.h"
#include "Prototype.h"

void Target::Request()
{
	cout<<"��ͨ����\n";
}

void Adaptee::SpecificRequest()
{
	cout<<"��������!\n";
}

void Adapter::Request()
{
	m_Adaptee.SpecificRequest();
}
