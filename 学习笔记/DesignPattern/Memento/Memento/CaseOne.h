#pragma  once

#include <iostream>
#include <string>
using namespace std;

class RoleStateMemento;

class GameRole
{
public:
	int GetVit();
	int GetAtk();
	int GetDef();

	void SetVit(int nVit);
	void SetAtk(int nAtk);
	void SetDef(int nDef);

	void StateDisplay();
	void GetInitState();
	void Fight();

	RoleStateMemento* SaveState();
	void RecoveryState(RoleStateMemento* m);

private:
	int m_nVit;
	int m_nAtk;
	int m_nDef;
};

class RoleStateMemento
{
public:
	RoleStateMemento(int nVit, int nAtk, int nDef);
	~RoleStateMemento();

	int GetVit();
	int GetAtk();
	int GetDef();

private:
	int m_nVit;
	int m_nAtk;
	int m_nDef;
};

class RoleStateCaretaker
{
public:
	RoleStateCaretaker();
	~RoleStateCaretaker();

	RoleStateMemento* GetMemento();
	void SetMemento(RoleStateMemento* m);

private:
	RoleStateMemento* m_pMemento;
};