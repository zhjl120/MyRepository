#pragma  once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Proudct{     //��Ʒ�࣬�Ĳ�Ʒ�ɶ���������
public:
	void AddPart(string strPart);//��Ӳ���
	void show();//��ʾ���в���

private:
	vector<string> m_vecParts;//�൱��һ����Ʒ�������ж������
};

class Builder{    //��Ʒ�����࣬�����ò�Ʒ��3���������
public:
	virtual void BuildPartA() = 0;  
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual Proudct* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder  //�����Ʒ��
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();

	void BuildPartA();
	void BuildPartB();
	void BuildPartC();

	Proudct* GetResult();

private:
	Proudct* m_pProduct;  //����һ����Ʒ�����ָ��
};

class Director{	//ָ���ߣ��������Ʒ������
public:
	void Construct(Builder* pBuilder);//���ݴ���Ĳ�Ʒ���󣬹��������Ʒ
};