#include "stdafx.h"
#include "Prototype.h"


void ConcreteFlyweight::Operation( int nExtrinsicstate )
{
	cout<<"������Ԫ���ⲿ״̬�룺 "<<nExtrinsicstate<<"\n";
}


void UnsharedConcreteFlyweight::Operation( int nExtrinsicstate )
{
	cout<<"������ľ�����Ԫ���ⲿ״̬�룺 "<<nExtrinsicstate<<"\n";
}

FlyweightFactory::FlyweightFactory()
{
	m_mapFlyweight.insert(pair<int,ConcreteFlyweight*>(1,new ConcreteFlyweight));
	m_mapFlyweight.insert(pair<int,ConcreteFlyweight*>(2,new ConcreteFlyweight));
	m_mapFlyweight.insert(pair<int,ConcreteFlyweight*>(3,new ConcreteFlyweight));
}

FlyweightFactory::~FlyweightFactory()
{
}

Flyweight* FlyweightFactory::GetFlyweight( int nKey )
{
	ConcreteFlyweight* pc = m_mapFlyweight[nKey];
	
	return pc;
}
