#include "stdafx.h"
#include "CaseOne.h"

void SqlserverUser::Insert( string strUserName )
{
	cout<<"使用 SQLServer 插入 User\n";
}

std::string SqlserverUser::GetUser( int nID )
{
	cout<<"使用 SQLServer 获取 User\n";

	return string("");
}


void AccessUser::Insert( string strUserName )
{
	cout<<"使用 ACCESS 插入 User\n";
}

std::string AccessUser::GetUser( int nID )
{
	cout<<"使用 ACCESS 获取 User\n";

	return string("");
}


void SqlserverDepartment::Insert( string strDepartmentName )
{
	cout<<"使用 SQLServer 插入 Department\n";
}

std::string SqlserverDepartment::GetDepartment( int nID )
{
	cout<<"使用 SQLServer 获取 Department\n";

	return string("");
}


void AccessDepartment::Insert( string strDepartmentName )
{
	cout<<"使用 ACCESS 插入 Department\n";
}

std::string AccessDepartment::GetDepartment( int nID )
{
	cout<<"使用 ACCESS 获取 Department\n";

	return string("");
}


IUser* SqlserverFactory::CreateUser()
{
	return new SqlserverUser;
}

IDepartment* SqlserverFactory::CreateDepartment()
{
	return new SqlserverDepartment;
}

IUser* AccessFactory::CreateUser()
{
	return new AccessUser;
}

IDepartment* AccessFactory::CreateDepartment()
{
	return new AccessDepartment;
}


string DataAccess::m_strDBName = "ACCESS";

IUser* DataAccess::CreateUser()
{
	if(m_strDBName.compare("SQLServer") == 0)
		return new SqlserverUser;
	else if(m_strDBName.compare("ACCESS") == 0)
		return new AccessUser;
}

IDepartment* DataAccess::CreateDepartment()
{
	if(m_strDBName.compare("SQLServer") == 0)
		return new SqlserverDepartment;
	else if(m_strDBName.compare("ACCESS") == 0)
		return new AccessDepartment;
}
