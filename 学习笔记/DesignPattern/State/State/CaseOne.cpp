#include "stdafx.h"
#include "CaseOne.h"

void ForenoonState::WriteProgram( Work* w )
{
	if(w->GetTime() < 12)
	{
		cout<<"��ǰʱ�䣺"<<w->GetTime()<<"�㣬���繤��������ٱ�\n";
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
		cout<<"��ǰʱ�䣺"<<w->GetTime()<<"�㣬���ˣ������緹��ʼ����\n";
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
		cout<<"��ǰʱ�䣺"<<w->GetTime()<<"�㣬״̬������������\n";
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
			cout<<"��ǰʱ�䣺"<<w->GetTime()<<"�㣬���ڼӰ࣬�ǳ�ƣ��\n";
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
	cout<<"��ǰʱ�䣺"<<w->GetTime()<<"�㣬˯����\n";
}

void ResetState::WriteProgram( Work* w )
{
	cout<<"��ǰʱ�䣺"<<w->GetTime()<<"�㣬׼���ؼ�\n";
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


