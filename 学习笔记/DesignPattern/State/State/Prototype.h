#pragma  once

#include <iostream>
using namespace std;

class C_Context;

class C_State
{
public:
	virtual void Handle(C_Context* pContext) = 0;
};

class ConcreteStateA : public C_State
{
public:
	void Handle(C_Context* pContext);
};

class ConcreteStateB : public C_State
{
	void Handle(C_Context* pContext);
};


class C_Context 
{
public:
	C_Context(C_State* pState);
	~C_Context();

	C_State* GetState();
	void SetState(C_State* pState);

	void Request();

private:
	C_State* m_pState;
};