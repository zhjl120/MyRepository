// Decorator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "CaseOne.h"
#include "CaseTwo.h"
#include "CaseThree.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{

//------------CaseOne--------------------------------------

	Person zhansan("����");

	cout<<"��һ��װ��:"<<endl;

	zhansan.show();
	zhansan.WearTShirts();
	zhansan.WearBigTrouser();
	zhansan.WearSneakers();

	cout<<"\n\n�ڶ���װ��:"<<endl;

	zhansan.show();
	zhansan.WearSuit();
	zhansan.WearTie();
	zhansan.WearLeatherShoes();



//------------CaseTwo-----------------------------------

	cout<<"\n\n������װ�磺\n";

	Person2 lisi("����");
	TShirts tshirt;
	BigTrouser trouser;
	Sneakers sneaker;

	lisi.show();
	tshirt.show();
	trouser.show();
	sneaker.show();

//------------CaseThree-----------------------------------
	//װ��ģʽ����̬�ĸ�һ���������һЩ�����ְ�𣬾����ӹ�����˵��װ��ģʽ�����������Ϊ��
	//װ��ģʽ��Ϊ���й��ܶ�̬����Ӹ��๦�ܵ�һ�ַ�ʽ��
	//װ��ģʽ��Ҫװ�εĹ��ܷ��ڵ��������У�����������װ����Ҫװ�εĶ�����ˣ�����Ҫִ��������Ϊ��ʱ�򣬿ͻ�����Ϳ���������
	//ʱ������ѡ��ء���˳���ʹ��װ�ι��ܰ�װ�����ˡ�
	//�ŵ㣺�����е�װ�ι��ܴ����а��Ƴ�ȥ���������Լ�ԭ�����ࡣ����Ч�İ���ĺ���ְ�ܺ�װ�ι������ֿ��ˣ����ҿ���ȥ���������
	//�ظ���װ���߼���

	cout<<"\n\n������װ�磺\n";

	Person3* wangwu = new Person3("����");
	TShirt3* tshirt3 = new TShirt3;
	BigTrouser3* trouser3 = new BigTrouser3;
	Sneakers3* sneaker3 = new Sneakers3;

	tshirt3->Decorate(wangwu);
	trouser3->Decorate(tshirt3);
	sneaker3->Decorate(trouser3);

	sneaker3->show();


	delete wangwu; delete tshirt3; delete trouser3; delete sneaker3;

	cout<<"\n\n\n";
	system("pause");
	return 0;
}

