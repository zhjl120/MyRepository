#include "stdafx.h"
#include "CaseTwo.h"

//-----------Base Class-------------------
CashSuper2::CashSuper2()
{
}

CashSuper2::~CashSuper2()
{
}

float CashSuper2::AcceptCash( float fMoney )
{
	return fMoney;
}


//-----------Cash Normal Class-------------------
CashNormal2::CashNormal2()
{
}

CashNormal2::~CashNormal2()
{
}

float CashNormal2::AcceptCash( float fMoney )
{
	return fMoney;
}


//-----------Cash Rebate Class-------------------
CashRebate2::CashRebate2(float fRebate)
{
	m_fRebate = fRebate;
}

CashRebate2::~CashRebate2()
{
}

float CashRebate2::AcceptCash( float fMoney )
{
	return fMoney * m_fRebate;
}

//-----------Cash Return Class-------------------
CashReturn2::CashReturn2(float fMoneyCondition, float fMoneyReturn)
{
	m_fMoneyCondition = fMoneyCondition;
	m_fMoneyReturn = fMoneyReturn;
}

CashReturn2::~CashReturn2()
{
}

float CashReturn2::AcceptCash( float fMoney )
{
	float fResult;

	if (fMoney > m_fMoneyCondition)
	{
		fResult = fMoney - fMoney / m_fMoneyCondition * m_fMoneyReturn;
	}

	return fResult;
}

//-----------CashContext Class-------------------
CashContext::CashContext(CashSuper2* cs )
{
	m_CashSuper = cs;
}

CashContext::~CashContext()
{
}

float CashContext::GetTotalPrices( float fMoney )
{
	return m_CashSuper->AcceptCash(fMoney);
}

void CashContext::Release()
{
	delete this;
}

