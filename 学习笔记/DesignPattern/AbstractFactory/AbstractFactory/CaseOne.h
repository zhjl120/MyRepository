#pragma once
#include <iostream>
#include <string>
using namespace std;

class IUser
{
public:
	virtual void Insert(string strUserName) = 0;
	virtual string GetUser(int nID) = 0;
};

class SqlserverUser : public IUser
{
public:
	void Insert(string strUserName);
	string GetUser(int nID);
};

class AccessUser : public IUser
{
public:
	void Insert(string strUserName);
	string GetUser(int nID);
};


class IDepartment
{
public:
	virtual void Insert(string strDepartmentName) = 0;
	virtual string GetDepartment(int nID) = 0;
};

class SqlserverDepartment : public IDepartment
{
public:
	void Insert(string strDepartmentName);
	string GetDepartment(int nID);
};

class AccessDepartment : public IDepartment
{
public:
	void Insert(string strDepartmentName);
	string GetDepartment(int nID);
};


class IFactory
{
public:
	virtual IUser* CreateUser() = 0;
	virtual IDepartment* CreateDepartment() = 0;
};

class SqlserverFactory : public IFactory
{
public:
	IUser* CreateUser();
	IDepartment* CreateDepartment();
};

class AccessFactory : public IFactory
{
public:
	IUser* CreateUser();
	IDepartment* CreateDepartment();
};


class DataAccess
{
public:
	static IUser* CreateUser();
	static IDepartment* CreateDepartment();

private:
	static string m_strDBName;
};