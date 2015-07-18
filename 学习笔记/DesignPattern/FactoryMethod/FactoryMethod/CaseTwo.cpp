#include "stdafx.h"
#include "CaseTwo.h"

OperationBase2::OperationBase2()
{
	m_fNum1 = 0;
	m_fNum2 = 0;
}

OperationBase2::~OperationBase2()
{
}

void OperationBase2::Release()
{
	delete this;
}

void OperationBase2::SetNum1( float fNum1 )
{
	m_fNum1 = fNum1;
}

void OperationBase2::SetNum2( float fNum2 )
{
	m_fNum2 = fNum2;
}

float OperationBase2::GetResult()
{
	return 0;
}


//--------------------Operation Class---------------------

float OperationAdd2::GetResult()
{
	return m_fNum1 + m_fNum2;
}

float OperationSub2::GetResult()
{
	return m_fNum1 - m_fNum2;
}

float OperationMul2::GetResult()
{
	return m_fNum1 * m_fNum2;
}

float OperationDiv2::GetResult()
{
	return m_fNum1 / m_fNum2;
}


//-------------具体工厂类---------------------
OperationBase2* AddFactory::CreateOperation()
{
	return new OperationAdd2;
}

OperationBase2* SubFactory::CreateOperation()
{
	return new OperationSub2;
}

OperationBase2* MulFactory::CreateOperation()
{
	return new OperationMul2;
}

OperationBase2* DivFactory::CreateOperation()
{
	return new OperationDiv2;
}
