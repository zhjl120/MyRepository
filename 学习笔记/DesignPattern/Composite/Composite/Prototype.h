#pragma  once

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Component
{
public:
	Component(string strName);
	~Component();

	virtual void Add(Component* c);
	virtual void Remove(Component* c);
	virtual void Display(int nDepth);

protected:
	string m_strName;
};

class Leaf : public Component
{
public:
	Leaf(string strName);
	~Leaf();

	void Add(Component* c);
	void Remove(Component* c);
	void Display(int nDepth);
};

class Composite : public Component
{
public:
	Composite(string strName);
	~Composite();

	void Add(Component* c);
	void Remove(Component* c);
	void Display(int nDepth);

private:
	list<Component*> m_ChildrenList;
};