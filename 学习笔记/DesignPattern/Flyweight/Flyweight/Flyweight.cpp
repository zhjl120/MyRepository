// Flyweight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//��Ԫģʽ�����ù�������Ч��֧�ִ���ϸ���ȵĶ���
	//�ڲ�״̬������Ԫ�����ڲ����Ҳ����滷���ı���ı�Ĺ����֡�
	//�ⲿ״̬���滷���ı���ı�ġ������Թ����״̬��
	//Ӧ�ã����һ��Ӧ�ó���ʹ���˴����Ķ��󣬶���������Щ��������˺ܴ�Ĵ洢����ʱ��Ӧ�ÿ���ʹ�á����о��Ƕ���Ĵ����״̬�������ⲿ״̬��
	//		      ���ɾ��������ⲿ״̬����ô��������Խ��ٵĹ������ȡ��������󣬴�ʱ���Կ���ʹ����Ԫģʽ��

	int nExtrinsicstate = 10;

	FlyweightFactory f;

	Flyweight* pFlyweight1 = f.GetFlyweight(1);
	pFlyweight1->Operation(nExtrinsicstate++);

	Flyweight* pFlyweight2 = f.GetFlyweight(2);
	pFlyweight1->Operation(nExtrinsicstate++);

	Flyweight* pFlyweight3 = f.GetFlyweight(3);
	pFlyweight1->Operation(nExtrinsicstate++);

	Flyweight* pUnshared = new UnsharedConcreteFlyweight;

	pUnshared->Operation(nExtrinsicstate++);

	//--------------------------------------------------
	cout<<"\n\n";

	WebsitFactory fac;

	WebSit* fx = fac.GetWebSit("��Ʒչʾ");
	fx->Use(User("zhansan"));

	WebSit* fy = fac.GetWebSit("��Ʒչʾ");
	fy->Use(User("lisi"));

	WebSit* fz = fac.GetWebSit("��Ʒչʾ");
	fz->Use(User("wangwu"));

	WebSit* fl = fac.GetWebSit("����");
	fl->Use(User("zhangtian"));

	WebSit* fm = fac.GetWebSit("����");
	fm->Use(User("wangliu"));

	WebSit* fn = fac.GetWebSit("����");
	fn->Use(User("zhangsi"));

	cout<<"��������"<<fac.GetObjectCount();


	cout<<"\n\n\n";
	system("pause");
	return 0;
}

