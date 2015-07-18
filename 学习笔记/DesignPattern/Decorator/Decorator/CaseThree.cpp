#include "stdafx.h"
#include "CaseThree.h"


Person3::Person3()
{
}

Person3::Person3(string szName)
{
	m_szName = szName;
}

Person3::~Person3()
{
}

void Person3::show()
{
	cout<<m_szName<<"的装扮：";//此处为需要修饰对象的核心功能模块
}


//-----修饰抽象类--------------------
Finery3::Finery3()
{
}

Finery3::~Finery3()
{
}

void Finery3::Decorate( Person3* component )//就需要修饰的对象传递进来
{
	m_Person = component;
}

void Finery3::show()
{
	if (m_Person != NULL)//装饰类的父类要做的就是调用被装饰类的核心模块。
	{
		m_Person->show();
	}
}


//---------具体服饰类------------------
void TShirt3::show()
{
	Finery3::show();//具体的装饰类，它们先执行被装饰类的功能。
	cout<<"T恤  ";//再在被装饰类的原始功能完成后，添加一些新的功能。
}

void BigTrouser3::show()
{
	Finery3::show();
	cout<<"大垮裤  ";
}

void Sneakers3::show()
{
	Finery3::show();
	cout<<"破球鞋  ";
}

void Suit3::show()
{
	Finery3::show();
	cout<<"西装  ";
}
