#pragma  once
#include <iostream>
#include <string>
using namespace  std;

class Person3//��Ҫ���εĶ���
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


//--------------���γ�����-------------
class Finery3 : public Person3 //����Ҫװ�ε���̳С�
{
public:
	Finery3();
	~Finery3();

public:
	void  Decorate(Person3* component);//���а�������Ҫװ�����ָ�룬��������������ж�ԭ��������й��ܷ�װ
	void show();

protected:
	Person3* m_Person;
};


//-------------����������-------------------
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
