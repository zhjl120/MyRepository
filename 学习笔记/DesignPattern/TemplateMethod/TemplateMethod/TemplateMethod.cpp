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

	//模板方法：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中，模板方法使得子类可以不改变一个算法的框架即可重定义该算法的特定步骤。
	//模板方法模式是通过把不变行为搬迁到到父类中，去除子类中重复代码来体现它的优势。
	//当不变的和可变的行为在方法的子类实现中混合在一起的时候，不变的行为就会在子类中重复出现。通过模板方法模式把这些行为搬迁到单一的
	//地方，这样可以帮助子类摆脱重复不变行为的纠缠。

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

