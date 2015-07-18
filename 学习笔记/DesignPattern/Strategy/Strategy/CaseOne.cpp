#include "stdafx.h"
#include "CaseOne.h"

//-----------Base Class-------------------
CashSuper1::CashSuper1()
{
}

CashSuper1::~CashSuper1()
{
}

float CashSuper1::AcceptCash( float fMoney )
{
	return fMoney;
}


//-----------Cash Normal Class-------------------
CashNormal1::CashNormal1()
{
}

CashNormal1::~CashNormal1()
{
}

float CashNormal1::AcceptCash( float fMoney )
{
	return fMoney;
}


//-----------Cash Rebate Class-------------------
CashRebate1::CashRebate1(float fRebate)
{
	m_fRebate = fRebate;
}

CashRebate1::~CashRebate1()
{
}

float CashRebate1::AcceptCash( float fMoney )
{
	return fMoney * m_fRebate;
}

//-----------Cash Return Class-------------------
CashReturn1::CashReturn1(float fMoneyCondition, float fMoneyReturn)
{
	m_fMoneyCondition = fMoneyCondition;
	m_fMoneyReturn = fMoneyReturn;
}

CashReturn1::~CashReturn1()
{
}

float CashReturn1::AcceptCash( float fMoney )
{
	float fResult;

	if (fMoney > m_fMoneyCondition)
	{
		fResult = fMoney - fMoney / m_fMoneyCondition * m_fMoneyReturn;
	}

	return fResult;
}


//-----------CashFactory Class-------------------
CashFactory::CashFactory()
{
}

CashFactory::~CashFactory()
{
}

CashSuper1* CashFactory::CreateCashAccept( DWORD dwType )
{
	CashSuper1* pCashSuper = NULL;

	float fRebate = 0.8;
	float fCondiion = 300 , fReturnVa = 100;

	switch(dwType)
	{
	case 1:
		pCashSuper = new CashNormal1;
		break;
	case 2:	
		pCashSuper = new CashRebate1(fRebate);
		break;
	case 3:
		pCashSuper = new CashReturn1(fCondiion, fReturnVa);
		break;
	default:
		break;
	}

	return pCashSuper;
}

void CashFactory::Release()
{
	delete this;
}
