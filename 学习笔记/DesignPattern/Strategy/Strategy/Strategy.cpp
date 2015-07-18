#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "CaseOne.h"
#include "CaseTwo.h"
#include "CaseThree.h"

using namespace std;

#define  ITEM_NORMAL			0x1
#define  ITEM_REBATE			0x2
#define  ITEM_RETURN			0x3

int _tmain(int argc, _TCHAR* argv[])
{
	float fTotalPrices = 0;
	float fPrice = 0, fCount = 0;	

	cout<<"Price: ";
	cin>>fPrice;

	cout<<"Count: ";
	cin>>fCount;


//--------------------test 1------------------------

	cout<<"Total Prices: "<<fPrice*fCount<<endl; 


//--------------------test 2------------------------

	switch(ITEM_NORMAL)
	{
	case 1:
		fTotalPrices = fPrice*fCount;
		break;
	case 2:
		fTotalPrices = fPrice*fCount * 0.8;
		break;
	case 3:
		fTotalPrices = fPrice*fCount * 0.7;
		break;
	case 4:
		fTotalPrices = fPrice*fCount * 0.5;
		break;
	default:
		break;
	}

	
	//--------------------Simple Factory------------------------

	CashSuper1* pCashSuper1 = CashFactory::CreateCashAccept(ITEM_NORMAL);
	cout<<"(Simple Factory - Normal)Total Prices: "<<pCashSuper1->AcceptCash(fCount * fPrice)<<endl;

	CashSuper1* pCashSuper2 = CashFactory::CreateCashAccept(ITEM_REBATE);
	cout<<"(Simple Factory - Rebate)Total Prices: "<<pCashSuper2->AcceptCash(fCount * fPrice)<<endl;

	CashSuper1* pCashSuper3 = CashFactory::CreateCashAccept(ITEM_RETURN);
	cout<<"(Simple Factory - ReturnCash)Total Prices: "<<pCashSuper3->AcceptCash(fCount * fPrice)<<endl;




	//--------------------Strategy------------------------

	CashContext* context1 = new CashContext(new CashNormal2);
	cout<<"(Strategy - Normal)Total Prices: "<<context1->GetTotalPrices(fCount * fPrice)<<endl;

	float fRebate = 0.8;
	CashRebate2* pRebate = new CashRebate2(fRebate);
	CashContext* context2 = new CashContext(pRebate);
	cout<<"(Strategy - Rebate)Total Prices: "<<context2->GetTotalPrices(fCount * fPrice)<<endl;

	float fCondition = 300, fReturnVa = 100;
	CashReturn2*  pReturnVa = new CashReturn2(fCondition, fReturnVa);
	CashContext* context3 = new CashContext(pReturnVa);
	cout<<"(Strategy - ReturnCash)Total Prices: "<<context3->GetTotalPrices(fCount * fPrice)<<endl;


	//����ģʽ��Ϊ�˽�����Ե��л�����չ��������˵���Ƕ�������壬�ֱ��װ������������֮������໥�滻,
	//����ģʽ�ò��Եı仯������ʹ�ò��ԵĿͻ�������Ӧ�õĳ������Ż�ϵͳ�����ʼ���ϵͳ�ȡ�
	//����ģʽ��Ҫ���������Դ��ͳһ�ַ���������Ĵ�����ȫ�����������ö���Ĵ����;����ʹ�ÿͻ��޹ء�
	//��ҪӦ���ڶ����ݿ�ѡ������ļ����صȡ�
	//�����Ե��ǲ���ģʽ�ǿ��ŵģ���Ϊһ��������Ļ��Χ��ȫ�̵ģ����������Ҫ���Լ�������Ϊ��
	//������ģʽ���Ƿ�յģ���Ϊ�������Ļ��Χ�����޵ģ��ܶ����鶼���������ˣ���ֱ�ӡ��㡱�Ϳ����ˡ�


	//--------------------Strategy + Simple Factory------------------------

	CashContext3 ssContext1(ITEM_NORMAL);
	cout<<"(Strategy+Factory - Normal)Total Prices: "<<ssContext1.GetTotalPrices(fPrice * fCount)<<endl;

	CashContext3 ssContext2(ITEM_REBATE);
	cout<<"(Strategy+Factory - Normal)Total Prices: "<<ssContext2.GetTotalPrices(fPrice * fCount)<<endl;

	CashContext3 ssContext3(ITEM_RETURN);
	cout<<"(Strategy+Factory - Normal)Total Prices: "<<ssContext3.GetTotalPrices(fPrice * fCount)<<endl;


	system("pause");
	return 0;
}

