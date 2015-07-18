#pragma once

#include <iostream>
#include <string>
using namespace std;

class Memento;

class Originator
{
public:
	Memento* CreateMemento();
	void SetMemento(Memento* m);
	void Show();

	void SetState(string strState);
	string GetState();

private:
	string m_strState;
};

class Memento
{
public:
	Memento(string strState);
	~Memento();

	string GetState();

private:
	string m_strState;
};

class Caretaker
{
public:
	Caretaker();
	~Caretaker();

	Memento* GetMemento();
	void SetMemento(Memento* m);

private:
	Memento* m_pMemento;
};