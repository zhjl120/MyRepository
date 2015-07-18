#pragma  once
#include <iostream>
#include <string>
using namespace  std;

class Person3//需要修饰的对象
{
public: 
	Person3();
	Person3(string szName);
	~Person3();

public: 
	virtual void show();

private:
	string m_szName;
};


//--------------修饰抽象类-------------
class Finery3 : public Person3 //从需要装饰的类继承。
{
public:
	Finery3();
	~Finery3();

public:
	void  Decorate(Person3* component);//类中包含了需要装饰类的指针，用于在这个子类中对原来的类进行功能封装
	void show();

protected:
	Person3* m_Person;
};


//-------------具体修饰类-------------------
class TShirt3 : public Finery3
{
public:
	void show();
};

class BigTrouser3 : public Finery3
{
public:
	void show();
};

class Sneakers3 : public Finery3
{
public:
	void show();
};

class Suit3 : public Finery3
{
public:
	void show();
};
