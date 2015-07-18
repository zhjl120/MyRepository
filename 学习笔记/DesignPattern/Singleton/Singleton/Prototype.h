#pragma once

#include <iostream>
#include <afxmt.h>
using namespace std;

class Singleton
{
private:	//˽��
	Singleton();
	~Singleton();

public:
	static Singleton* GetInstance();//��̬
	static void DestroyInstance();

	static void Test();

private:
	static Singleton* m_pSingleton;
	static CMutex* m_pMutex;
};