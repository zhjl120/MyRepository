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
	cout<<m_szName<<"��װ�磺";//�˴�Ϊ��Ҫ���ζ���ĺ��Ĺ���ģ��
}


//-----���γ�����--------------------
Finery3::Finery3()
{
}

Finery3::~Finery3()
{
}

void Finery3::Decorate( Person3* component )//����Ҫ���εĶ��󴫵ݽ���
{
	m_Person = component;
}

void Finery3::show()
{
	if (m_Person != NULL)//װ����ĸ���Ҫ���ľ��ǵ��ñ�װ����ĺ���ģ�顣
	{
		m_Person->show();
	}
}


//---------���������------------------
void TShirt3::show()
{
	Finery3::show();//�����װ���࣬������ִ�б�װ����Ĺ��ܡ�
	cout<<"T��  ";//���ڱ�װ�����ԭʼ������ɺ����һЩ�µĹ��ܡ�
}

void BigTrouser3::show()
{
	Finery3::show();
	cout<<"����  ";
}

void Sneakers3::show()
{
	Finery3::show();
	cout<<"����Ь  ";
}

void Suit3::show()
{
	Finery3::show();
	cout<<"��װ  ";
}
