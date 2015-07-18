#pragma  once

#include "CaseTwo.h"

class OperationFactory{
public: 
	OperationFactory();
	~OperationFactory();

public:
	OperationBase* CreateOperation(char cSymbol);
};