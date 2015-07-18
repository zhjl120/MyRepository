#include "stdafx.h"
#include "CaseOne.h"


User::User( string strName )
{
	m_strName = strName;
}

std::string User::GetName()
{
	return m_strName;
}

ConcreteWebSits::ConcreteWebSits( string strName )
{
	m_strName = strName;
}

void ConcreteWebSits::Use( User user )
{
	cout<<"网站分类："+m_strName+"  用户："+user.GetName()<<"\n";
}

ConcreteWebSits* WebsitFactory::GetWebSit( string strKey )
{
	map<string,ConcreteWebSits*>::iterator it;

	it = m_mapFlyweight.find(strKey);

	if(it == m_mapFlyweight.end())
	{
		ConcreteWebSits* pw = new ConcreteWebSits(strKey);
		m_mapFlyweight.insert(pair<string,ConcreteWebSits*>(strKey, pw));
		return pw;
	}

	return it->second;
}

int WebsitFactory::GetObjectCount()
{
	return m_mapFlyweight.size();
}
