#include "stdafx.h"
#include "CaseOne.h"


void Barbecuer::BakeMutton()
{
	cout<<"¿¾ÑòÈâ´®\n";
}

void Barbecuer::BakeChickenWing()
{
	cout<<"¿¾¼¦³á\n";
}


Command2::Command2( Barbecuer receiver )
{
	m_receiver = receiver;
}


BakeMuttonCommand::BakeMuttonCommand( Barbecuer receiver ):Command2(receiver)
{
}

void BakeMuttonCommand::ExecuteCommand()
{
	m_receiver.BakeMutton();
}


BakeChickenWingCommand::BakeChickenWingCommand( Barbecuer receiver ): Command2(receiver)
{
}

void BakeChickenWingCommand::ExecuteCommand()
{
	m_receiver.BakeChickenWing();
}


void Waiter::SetOrder( Command2* cmd )
{
	m_CmdList.push_back(cmd);
}

void Waiter::CancelOrder( Command2* cmd )
{
	m_CmdList.remove(cmd);
}

void Waiter::Notify()
{
	for (CommandList::iterator it = m_CmdList.begin() ; it != m_CmdList.end(); ++it)
	{
		(*it)->ExecuteCommand();
	}
}
