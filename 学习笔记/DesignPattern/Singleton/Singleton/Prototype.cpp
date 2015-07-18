#include "stdafx.h"
#include "Prototype.h"

Singleton* Singleton::m_pSingleton = NULL;
CMutex* Singleton::m_pMutex = new CMutex;

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

Singleton* Singleton::GetInstance()
{
	if (m_pSingleton == NULL)
	{
		m_pMutex->Lock();

		if(m_pSingleton == NULL)
			m_pSingleton = new Singleton;

		m_pMutex->Unlock();
	}

	return m_pSingleton;
}

void Singleton::DestroyInstance()
{
	if(m_pSingleton != NULL)
	{
		delete m_pSingleton;
		m_pSingleton = NULL;
	}

	delete m_pMutex;
	m_pMutex = NULL;
}

void Singleton::Test()
{
	cout<<"this is test\n";
}



