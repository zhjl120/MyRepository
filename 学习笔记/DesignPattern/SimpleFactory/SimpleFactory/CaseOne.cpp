#include "stdafx.h"
#include "CaseOne.h"

Operation::Operation()
{
}

Operation::~Operation()
{
}

float Operation::GetResult( float fNum1, float fNum2, char cOperate )
{
	float fResult = 0;

	switch(cOperate)
	{
	case '+':
		fResult = fNum1+fNum2;
		break;
	case  '-':
		fResult = fNum1-fNum2;
		break;
	case '*':
		fResult = fNum1*fNum2;
		break;
	case '/':
		fResult = fNum1/fNum2;
		break;
	default:
		break;
	}

	return fResult;
}
