#include "stdafx.h"
#include "Prototype.h"

Component::Component( string strName )
{
	m_strName = strName;
}

Component::~Component()
{
}

void Component::Add( Component* c )
{
}

void Component::Remove( Component* c )
{
}

void Component::Display( int nDepth )
{
	cout<<m_strName<<endl;
}


Leaf::Leaf( string strName ) : Component(strName)
{
}

Leaf::~Leaf()
{
}

void Leaf::Add( Component* c )
{
}

void Leaf::Remove( Component* c )
{
}

void Leaf::Display( int nDepth )
{
	for (int nIndex = 0; nIndex < nDepth ; nIndex ++)
		cout<<"-";

	cout<<m_strName<<endl;
}


Composite::Composite( string strName ) : Component(strName)
{
}

Composite::~Composite()
{
}

void Composite::Add( Component* c )
{
	m_ChildrenList.push_back(c);
}

void Composite::Remove( Component* c )
{
	m_ChildrenList.remove(c);
}

void Composite::Display( int nDepth )
{
	for (int nIndex = 0; nIndex < nDepth ; nIndex ++)
		cout<<"-";

	cout<<m_strName<<endl;
	

	for (list<Component*>::iterator it = m_ChildrenList.begin(); it != m_ChildrenList.end(); it++)
	{
		(*it)->Display(nDepth+2);
	}
}

