#include "stdafx.h"
#include "OperationFactory.h"

OperationFactory::OperationFactory()
{
}

OperationFactory::~OperationFactory()
{
}

OperationBase* OperationFactory::CreateOperation( char cSymbol )
{
	switch(cSymbol)
	{
	case '+':
		return new OperationAdd;
	case  '-':
		return new OperationSub;
	case '*':
		return new OperationMul;
	case '/':
		return new OperationDiv;
	default:
		return NULL;
	}
}


