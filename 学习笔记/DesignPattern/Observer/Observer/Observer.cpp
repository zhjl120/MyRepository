// Observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CaseOne.h"
//#include "Prototype.h"
#include<Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Secretary* sec = new Secretary;

	StockObserver* tongshi1 = new StockObserver("Linda",sec);//�۲������ּ��۲�Ķ���
	NBAObserver* tongshi2 = new NBAObserver("Dexter",sec);

	sec->Attach(tongshi1);//֪ͨ�ߵȼ��۲���
	sec->Attach(tongshi2);
//	sec->Detach(tongshi2);

	sec->SetSubjectState("boss coming  ");//֪ͨ������֪ͨ����Ϣ

	sec->Notify();//֪ͨ���й۲���

	//�۲���ģʽ��������һ��һ�Զ��������ϵ���ö���۲��߶���ͬʱ����ĳһ�������������������
	//��״̬�����仯ʱ����֪ͨ���й۲��߶���ʹ�����ܹ��Զ�����֮�䡣
	//���ã��۲���ģʽ�����Ĺ�����ʵ�����ڽ����ϡ�����ϵ�˫���������ڳ�������������ھ��塣
	//           �Ӷ�ʹ�ø��Եı仯������Ӱ����һ�ߵı仯��
	//Ӧ�ã�1.��һ������ĸı���Ҫͬʱ�ı���������2.����֪�������ж��ٶ����д��ı�ʱ��Ӧ�ÿ���ʹ�ù۲���ģʽ��
	//------------------------------------------------------


	//ConcreteSubject* pSub = new ConcreteSubject;

	//pSub->Attach(new ConcreteObserver(pSub,"X"));
	//pSub->Attach(new ConcreteObserver(pSub,"Y"));

	//pSub->SetSubjectState("ABC");
	//pSub->Notify();


	cout<<"\n\n";
	system("pause");
	return 0;
}

