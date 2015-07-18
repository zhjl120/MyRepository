// Adapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//������ģʽ����һ����Ľӿ�ת��Ϊ�ͻ�ϣ��������һ���ӿڡ�Adapterģʽʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������
	//������ģʽ��Ϊ����������ģʽ�Ͷ���������ģʽ������ֻ�Ƕ���������ģʽ��

	Target* pTarget = new Adapter;
	pTarget->Request();


	cout<<"\n\n";
	//--------------------------------------------

	Player* pPlayer1 = new Forwards("Jack");
	pPlayer1->Attack();

	Player* pPlayer2 = new Guards("Damien");
	pPlayer2->Defense();

	Player* pPlayer3 = new Translator("Ҧ��");
	pPlayer3->Attack();
	pPlayer3->Defense();


	cout<<"\n\n";
	system("pause");
	return 0;
}

