// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Director director;
	Builder* b1 = new ConcreteBuilder1;
	
	director.Construct(b1);
	Proudct* p1 = b1->GetResult();
	p1->show();

	delete b1 ; b1 = NULL;
	p1 = NULL;


	cout<<"\n\n";
	//------------------------------------------------------------------
	//������ģʽ����һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
	//������ģʽ�ĺô��� ʹ�ý���������ʾ������룬���ڽ����������˸ò�Ʒ�������װ�ģ���������Ҫ�ı�һ����Ʒ���ڲ�
	//��ʾ��ֻ��Ҫ�ٶ���һ������Ľ����߾Ϳ����ˡ�
	
	PersonBuilder* pBuilder = new PersonThinBuilder;
	PersonDirector pDir(pBuilder);
	pDir.CreatePerson();

	delete pBuilder; pBuilder = NULL;

	cout<<"\n\n";
	system("pause");
	return 0;
}

