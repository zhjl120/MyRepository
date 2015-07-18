#include "stdafx.h"
#include "Prototype.h"


void Receiver::Action()
{
	cout<<"Eexcute Action\n";
}


Command::Command( Receiver receiver )
{
	m_pReceiver = receiver;
}


ConcreteCommand::ConcreteCommand( Receiver receiver ) : Command(receiver)
{
}

void ConcreteCommand::Execute()
{
	m_pReceiver.Action();
}


void Invoker::SetCommand( Command* cmd )
{
	m_pCmd = cmd;
}

void Invoker::ExecuteCommand()
{
	m_pCmd->Execute();
}
