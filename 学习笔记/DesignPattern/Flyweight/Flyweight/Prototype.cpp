#include "stdafx.h"
#include "Prototype.h"


void ConcreteFlyweight::Operation( int nExtrinsicstate )
{
	cout<<"具体享元，外部状态码： "<<nExtrinsicstate<<"\n";
}


void UnsharedConcreteFlyweight::Operation( int nExtrinsicstate )
{
	cout<<"不共享的具体享元，外部状态码： "<<nExtrinsicstate<<"\n";
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
