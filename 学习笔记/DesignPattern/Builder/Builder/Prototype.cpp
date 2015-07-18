#include "stdafx.h"
#include "Prototype.h"

void Proudct::AddPart( string strPart )
{
	m_vecParts.push_back(strPart);
}

void Proudct::show()
{
	for (vector<string>::iterator it = m_vecParts.begin(); it != m_vecParts.end(); it++)
	{
		cout<<"Part: "<<*it<<endl;
	}
}


ConcreteBuilder1::ConcreteBuilder1()
{
	m_pProduct = new Proudct;
}

ConcreteBuilder1::~ConcreteBuilder1()
{
	if (m_pProduct != NULL)
	{
		delete m_pProduct ;
		m_pProduct = NULL;
	}
}

void ConcreteBuilder1::BuildPartA()
{
	m_pProduct->AddPart("部件A");
}

void ConcreteBuilder1::BuildPartB()
{
	m_pProduct->AddPart("部件B");
}

void ConcreteBuilder1::BuildPartC()
{
	m_pProduct->AddPart("部件C");
}

Proudct* ConcreteBuilder1::GetResult()
{
	return m_pProduct;
}

void Director::Construct( Builder* pBuilder )
{
	pBuilder->BuildPartA();
	pBuilder->BuildPartB();
	pBuilder->BuildPartC();
}
