#pragma once

#include <iostream>
using namespace std;

class Work;

class C_State2
{
public:
	virtual void WriteProgram(Work* w) = 0;
};

class ForenoonState : public C_State2
{
public:
	void WriteProgram(Work* w);
};

class NoonState : public C_State2
{
public:
	void WriteProgram(Work* w);
};

class AfternoonState : public C_State2
{
public:
	void WriteProgram(Work* w);
};

class EveningState : public C_State2
{
public:
	void WriteProgram(Work* w);
};

class SleepingState : public C_State2
{
public:
	void WriteProgram(Work* w);
};

class ResetState : public C_State2
{
public:
	void WriteProgram(Work* w);
};


class Work
{
public:
	Work();
	~Work();

public:
	double GetTime();
	void SetTime(double dTime);

	bool GetFinish();
	void SetFinish(bool bIsFinished);

	void SetState(C_State2* pState);
	void WriteProgram();

private:
	double m_dWrokTime;
	bool m_bIsFinished;
	C_State2* m_pState;
};