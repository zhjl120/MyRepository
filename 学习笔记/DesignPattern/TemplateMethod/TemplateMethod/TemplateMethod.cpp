// TemplateMethod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
#include "CaseTwo.h"
#include "CaseThree.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//TestPaperA  a;
	//a.TestQusetion1();
	//a.TestQusetion2();
	//a.TestQusetion3();
	//a.TestQusetion4();
	//a.TestQusetion5();

	//cout<<"---------------------------------------------\n";

	//TestPaperB b;
	//b.TestQusetion1();
	//b.TestQusetion2();
	//b.TestQusetion3();
	//b.TestQusetion4();
	//b.TestQusetion5();

	//--------------------------------------------------

	//TestPaperC c;
	//c.Answer1();
	//c.Answer2();
	//c.Answer3();
	//c.Answer4();
	//c.Answer5();

	//cout<<"---------------------------------------------\n";

	//TestPaperD d;
	//d.Answer1();
	//d.Answer2();
	//d.Answer3();
	//d.Answer4();
	//d.Answer5();

	//ģ�巽��������һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������У�ģ�巽��ʹ��������Բ��ı�һ���㷨�Ŀ�ܼ����ض�����㷨���ض����衣
	//ģ�巽��ģʽ��ͨ���Ѳ�����Ϊ��Ǩ���������У�ȥ���������ظ������������������ơ�
	//������ĺͿɱ����Ϊ�ڷ���������ʵ���л����һ���ʱ�򣬲������Ϊ�ͻ����������ظ����֡�ͨ��ģ�巽��ģʽ����Щ��Ϊ��Ǩ����һ��
	//�ط����������԰�����������ظ�������Ϊ�ľ�����

	TestPaper2* pe = new TestPaperE;
	pe->TestQusetion1();
	pe->TestQusetion2();
	pe->TestQusetion3();
	pe->TestQusetion4();
	pe->TestQusetion5();

	cout<<"---------------------------------------------\n";

	TestPaper2* pf = new TestPaperF;
	pf->TestQusetion1();
	pf->TestQusetion2();
	pf->TestQusetion3();
	pf->TestQusetion4();
	pf->TestQusetion5();


	delete pe; delete pf;

	system("pause");
	return 0;
}

