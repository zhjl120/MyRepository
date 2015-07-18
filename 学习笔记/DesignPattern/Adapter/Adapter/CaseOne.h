#pragma  once

#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	Player(string strName);
	~Player();

public:
	virtual void Attack() = 0;
	virtual void Defense() = 0;

protected:
	string m_strName;
};

class Forwards : public Player
{
public:
	Forwards(string strName);
	~Forwards();

	void Attack();
	void Defense();
};

class Guards : public Player
{
public:
	Guards(string strName);
	~Guards();

	void Attack();
	void Defense();
};

class ForeignCenter
{
public:
	ForeignCenter();
	~ForeignCenter();

	void Attack();
	void Defense();
	void SetName(string strName);

private:
	string m_strName;
};

class Translator : public Player
{
public:
	Translator(string strName);
	~Translator();

	void Attack();
	void Defense();

private:
	ForeignCenter m_foreignCenter;
};