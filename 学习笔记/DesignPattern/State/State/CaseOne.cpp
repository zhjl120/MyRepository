#include "stdafx.h"
#include "CaseOne.h"

void ForenoonState::WriteProgram( Work* w )
{
	if(w->GetTime() < 12)
	{
		cout<<"当前时间："<<w->GetTime()<<"点，上午工作，精神百倍\n";
	}
	else
	{
		w->SetState(new NoonState);
		w->WriteProgram();
	}
}

void NoonState::WriteProgram( Work* w )
{
	if(w->GetTime() < 13)
	{
		cout<<"当前时间："<<w->GetTime()<<"点，饿了，吃完午饭开始午休\n";
	}
	else
	{
		w->SetState(new AfternoonState);
		w->WriteProgram();
	}
}

void AfternoonState::WriteProgram( Work* w )
{
	if (w->GetTime()  < 17)
	{
		cout<<"当前时间："<<w->GetTime()<<"点，状态不错，继续工作\n";
	}
	else
	{
		w->SetState(new EveningState);
		w->WriteProgram();
	}
}

void EveningState::WriteProgram( Work* w )
{
	if (w->GetFinish())
	{
		w->SetState(new ResetState);
		w->WriteProgram();
	}
	else
	{
		if(w->GetTime() < 21)
		{
			cout<<"当前时间："<<w->GetTime()<<"点，正在加班，非常疲劳\n";
		}
		else
		{
			w->SetState(new SleepingState);
			w->WriteProgram();
		}
	}
}

void SleepingState::WriteProgram( Work* w )
{
	cout<<"当前时间："<<w->GetTime()<<"点，睡着了\n";
}

void ResetState::WriteProgram( Work* w )
{
	cout<<"当前时间："<<w->GetTime()<<"点，准备回家\n";
}


Work::Work()
{
	m_pState = new ForenoonState;
	m_bIsFinished =false;
}

Work::~Work()
{
	if (m_pState != NULL)
	{
		delete m_pState;
		m_pState = NULL;
	}
}

double Work::GetTime()
{
	return m_dWrokTime;
}

void Work::SetTime( double dTime )
{
	m_dWrokTime = dTime;
}

bool Work::GetFinish()
{
	return m_bIsFinished;
}

void Work::SetFinish(bool bIsFinished)
{
	m_bIsFinished = bIsFinished;
}

void Work::SetState( C_State2* pState )
{
	if(m_pState != NULL)
	{
		delete m_pState;
		m_pState = NULL;
	}
	m_pState = pState;
}

void Work::WriteProgram()
{
	m_pState->WriteProgram(this);
}


