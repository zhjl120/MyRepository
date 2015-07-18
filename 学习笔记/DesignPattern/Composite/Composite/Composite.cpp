// Composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//���ģʽ����������ϳ����νṹ�Ա�ʾ'����-����'�Ĳ�νṹ�����ģʽʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�
	//ʹ�ã��������������ֲ����������νṹʱ���Լ���ϣ���û����Ժ�����϶����뵥������Ĳ�ͬ��ͳһ��ʹ����Ͻṹ�е�
	//���ж���ʱ����Ӧ�ÿ���ʹ�����ģʽ��
	//���ģʽ�ÿͻ�����һ�µ�ʹ����Ͻṹ�͵�������
	//C++�ͷ�ָ�뽨�飺���release������ɾ��list�е�����ָ�롣

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

	
	ConcreteCompany root2("�����ܹ�˾");
	root2.Add(new HRDepartment("�ܹ�˾������Դ��"));
	root2.Add(new FinanceDepartment("�ܹ�˾����"));

	ConcreteCompany com("�Ϻ������ֹ�˾");
	com.Add(new HRDepartment("�����ֹ�˾������Դ��"));
	com.Add(new FinanceDepartment("�����ֹ�˾����"));

	root2.Add(&com);

	ConcreteCompany com2("�Ͼ����´�");
	com2.Add(new HRDepartment("�Ͼ����´�������Դ��"));
	com2.Add(new FinanceDepartment("�Ͼ����´�����"));
	com.Add(&com2);

	ConcreteCompany com3("���ݰ��´�");
	com3.Add(new HRDepartment("���ݰ��´�������Դ��"));
	com3.Add(new FinanceDepartment("���ݰ��´�����"));
	com.Add(&com3);

	cout<<"�ṹͼ:\n\n";
	root2.Display(1);
	cout<<"ְ��:\n\n";
	root2.LineOfDuty();



	cout<<"\n\n";
	system("pause");
	return 0;
}

