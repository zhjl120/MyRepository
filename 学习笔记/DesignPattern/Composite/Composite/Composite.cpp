// Composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//组合模式：将对象组合成树形结构以表示'部分-整体'的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
	//使用：当需求中是体现部分与整体层次结构时，以及你希望用户可以忽略组合对象与单个对象的不同，统一地使用组合结构中的
	//所有对象时，就应该考虑使用组合模式。
	//组合模式让客户可以一致的使用组合结构和单个对象。
	//C++释放指针建议：添加release函数，删除list中的所有指针。

	Composite root("Root");
	root.Add(new Leaf("Leaf A"));
	root.Add(new Leaf("Leaf B"));

	Composite comp("Composite X");
	comp.Add(new Leaf("Leaf XA"));
	comp.Add(new Leaf("Leaf XB"));

	root.Add(&comp);

	Composite comp2("Composite XY");
	comp2.Add(new Leaf("Leaf XYA"));
	comp2.Add(new Leaf("Leaf XYB"));

	comp.Add(&comp2);

	root.Add(new Leaf("Leaf C"));

	root.Display(1);


	cout<<"\n\n";
	//----------------------------------------------------------------

	
	ConcreteCompany root2("北京总公司");
	root2.Add(new HRDepartment("总公司人力资源部"));
	root2.Add(new FinanceDepartment("总公司财务部"));

	ConcreteCompany com("上海华东分公司");
	com.Add(new HRDepartment("华东分公司人力资源部"));
	com.Add(new FinanceDepartment("华东分公司财务部"));

	root2.Add(&com);

	ConcreteCompany com2("南京办事处");
	com2.Add(new HRDepartment("南京办事处人力资源部"));
	com2.Add(new FinanceDepartment("南京办事处财务部"));
	com.Add(&com2);

	ConcreteCompany com3("杭州办事处");
	com3.Add(new HRDepartment("杭州办事处人力资源部"));
	com3.Add(new FinanceDepartment("杭州办事处财务部"));
	com.Add(&com3);

	cout<<"结构图:\n\n";
	root2.Display(1);
	cout<<"职责:\n\n";
	root2.LineOfDuty();



	cout<<"\n\n";
	system("pause");
	return 0;
}

