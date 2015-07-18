#pragma once

#include <iostream>
#include <map>
#include <string>
using namespace std;


class User
{
public:
	User(string strName);
	string GetName();

private:
	string m_strName;
};


class WebSit
{
public:
	virtual void Use(User user) = 0;
};


class ConcreteWebSits : public WebSit
{
public:
	ConcreteWebSits(string strName);
	void Use(User user);

private:
	string m_strName;
};


class WebsitFactory
{
public:
	ConcreteWebSits* GetWebSit(string strKey);
	int GetObjectCount();

private:
	map<string,ConcreteWebSits*> m_mapFlyweight;
};