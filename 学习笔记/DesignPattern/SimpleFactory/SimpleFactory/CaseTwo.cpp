#include "stdafx.h"
#include "CaseTwo.h"

OperationBase::OperationBase()
{
	m_fNum1 = 0;
	m_fNum2 = 0;
}

OperationBase::~OperationBase()
{
}

void OperationBase::Release()
{
	delete this;
}

void OperationBase::SetNum1( float fNum1 )
{
	m_fNum1 = fNum1;
}

void OperationBase::SetNum2( float fNum2 )
{
	m_fNum2 = fNum2;
}

float OperationBase::GetResult()
{
	return 0;
}


//--------------------Operation Class---------------------

float OperationAdd::GetResult()
{
	return m_fNum1 + m_fNum2;
}

float OperationSub::GetResult()
{
	return m_fNum1 - m_fNum2;
}

float OperationMul::GetResult()
{
	return m_fNum1 * m_fNum2;
}

float OperationDiv::GetResult()
{
	return m_fNum1 / m_fNum2;
}
