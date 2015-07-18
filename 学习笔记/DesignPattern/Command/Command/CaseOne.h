#pragma once

#include <iostream>
#include <list>
using namespace std;

class Barbecuer
{
public:
	void BakeMutton();
	void BakeChickenWing();
};

class Command2
{
public:
	Command2(Barbecuer receiver);
	virtual void ExecuteCommand() = 0;

protected:
	Barbecuer m_receiver;
};

class BakeMuttonCommand : public Command2
{
public:
	BakeMuttonCommand(Barbecuer receiver);
	void ExecuteCommand();

};

class BakeChickenWingCommand : public Command2
{
public:
	BakeChickenWingCommand(Barbecuer receiver);
	void ExecuteCommand();
};

class Waiter
{
	typedef list<Command2*> CommandList;

public:
	void SetOrder(Command2* cmd);
	void CancelOrder(Command2* cmd);
	void Notify();

private:
	CommandList m_CmdList;
};