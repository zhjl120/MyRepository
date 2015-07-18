#pragma once

#include <iostream>
using namespace std;

class Receiver
{
public:
	void Action();
};

class Command
{
public:
	Command(Receiver receiver);
	virtual void Execute() = 0;

protected:
	Receiver m_pReceiver;
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver receiver);
	void Execute();
};

class Invoker
{
public:
	void SetCommand(Command* cmd);
	void ExecuteCommand();

private:
	Command* m_pCmd;
};

