#include "stdafx.h"
#include "CaseThree.h"

void LeiFeng::Sweep()
{
	cout<<"\n\nɨ��  ";
}

void LeiFeng::Wash()
{
	cout<<"ϴ�·�  ";
}

void LeiFeng::BuyRice()
{
	cout<<"����  ";
}


void Undergraduate::Sweep()
{
	cout<<"\n\n��ѧ����ɨ��  ";
}

void Undergraduate::Wash()
{
	cout<<"��ѧ����ϴ�·�  ";
}

void Undergraduate::BuyRice()
{
	cout<<"��ѧ��������  \n\n";
}

void Volunteer::Sweep()
{
	cout<<"\n\n־Ը�ߣ�ɨ��  ";
}

void Volunteer::Wash()
{
	cout<<"־Ը�ߣ�ϴ�·�  ";
}

void Volunteer::BuyRice()
{
	cout<<"־Ը�ߣ�����  \n\n";
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


