#include "stdafx.h"
#include "CaseThree.h"

void LeiFeng::Sweep()
{
	cout<<"\n\n扫地  ";
}

void LeiFeng::Wash()
{
	cout<<"洗衣服  ";
}

void LeiFeng::BuyRice()
{
	cout<<"买米  ";
}


void Undergraduate::Sweep()
{
	cout<<"\n\n大学生：扫地  ";
}

void Undergraduate::Wash()
{
	cout<<"大学生：洗衣服  ";
}

void Undergraduate::BuyRice()
{
	cout<<"大学生：买米  \n\n";
}

void Volunteer::Sweep()
{
	cout<<"\n\n志愿者：扫地  ";
}

void Volunteer::Wash()
{
	cout<<"志愿者：洗衣服  ";
}

void Volunteer::BuyRice()
{
	cout<<"志愿者：买米  \n\n";
}


LeiFeng* Factory::CreateLeiFeng()
{
	return new LeiFeng;
}

LeiFeng* UndergraduateFactory::CreateLeiFeng()
{
	return new Undergraduate;
}

LeiFeng* VolunteerFactory::CreateLeiFeng()
{
	return new Volunteer;
}


