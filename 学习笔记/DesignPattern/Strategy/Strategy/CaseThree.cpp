#include "stdafx.h"
#include "CaseThree.h"

//-----------Base Class-------------------
CashSuper3::CashSuper3()
{
}

CashSuper3::~CashSuper3()
{
}

float CashSuper3::AcceptCash( float fMoney )
{
	return fMoney;
}


//-----------Cash Normal Class-------------------
CashNormal3::CashNormal3()
{
}

CashNormal3::~CashNormal3()
{
}

float CashNormal3::AcceptCash( float fMoney )
{
	return fMoney;
}


//-----------Cash Rebate Class-------------------
CashRebate3::CashRebate3(float fRebate)
{
	m_fRebate = fRebate;
}

CashRebate3::~CashRebate3()
{
}

float CashRebate3::AcceptCash( float fMoney )
{
	return fMoney * m_fRebate;
}

//-----------Cash Return Class-------------------
CashReturn3::CashReturn3(float fMoneyCondition, float fMoneyReturn)
{
	m_fMoneyCondition = fMoneyCondition;
	m_fMoneyReturn = fMoneyReturn;
}

CashReturn3::~CashReturn3()
{
}

float CashReturn3::AcceptCash( float fMoney )
{
	float fResult;

	if (fMoney > m_fMoneyCondition)
	{
		fResult = fMoney - fMoney / m_fMoneyCondition * m_fMoneyReturn;
	}

	return fResult;
}

//-----------CashContext Class-------------------
CashContext3::CashContext3( DWORD dwType )
{
	float fRebate = 0.8;
	float fCondiion = 300 , fReturnVa = 100;

	switch(dwType)
	{
	case 1:
		m_CashSuper = new CashNormal3;
		break;
	case 2:	
		m_CashSuper = new CashRebate3(fRebate);
		break;
	case 3:
		m_CashSuper = new CashReturn3(fCondiion, fReturnVa);
		break;
	default:
		break;
	}
}

CashContext3::~CashContext3()
{
}

float CashContext3::GetTotalPrices( float fMoney )
{
	return m_CashSuper->AcceptCash(fMoney);
}

void CashContext3::Release()
{
	delete this;
}

