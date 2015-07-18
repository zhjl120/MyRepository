// State.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"
#include "CaseOne.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	C_Context context(new ConcreteStateA);

	context.Request();
	context.Request();
	context.Request();
	context.Request();

	//----------------------------------------------------------
	//״̬ģʽ����һ�����������״̬�ı�ʱ����ı�����Ϊ����������������Ǹı������ࡣ
	//״̬ģʽ��Ҫ������ǵ�����һ������״̬ת�����������ʽ���ڸ��ӵ��������״̬���ж��߼�ת�Ƶ���ʾ��ͬ״̬
	//��һϵ���൱�У����԰Ѹ��ӵ��ж��߼��򻯡�
	//�ô��� �����ض�״̬��ص���Ϊ�ֲ��������ҽ���ͬ״̬����Ϊ�ָ����
	//�ô��� ��һ���������Ϊȡ��������״̬������������������ʱ�̸���״̬�ı�������Ϊʱ���Ϳ��Կ���ʹ��״̬ģʽ��
	cout<<"------------------------------------------------\n";

	Work project;

	project.SetTime(9);			//����9�㣺��ʼ����
	project.WriteProgram();
	project.SetTime(10);		
	project.WriteProgram();
	project.SetTime(12);	   
	project.WriteProgram();
	project.SetTime(13);
	project.WriteProgram();
	project.SetTime(14);
	project.WriteProgram();
	project.SetTime(17);
	project.SetFinish(false);
	project.WriteProgram();
	project.SetTime(19);
	project.WriteProgram();
	project.SetTime(22);
	project.WriteProgram();


	cout<<"\n\n";
	system("pause");
	return 0;
}

