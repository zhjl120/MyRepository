#pragma  once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Proudct{     //产品类，改产品由多个部件组成
public:
	void AddPart(string strPart);//添加部件
	void show();//显示所有部件

private:
	vector<string> m_vecParts;//相当于一件产品，里面有多个部件
};

class Builder{    //产品抽象类，表明该产品由3个部分组成
public:
	virtual void BuildPartA() = 0;  
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual Proudct* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder  //具体产品类
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();

	void BuildPartA();
	void BuildPartB();
	void BuildPartC();

	Proudct* GetResult();

private:
	Proudct* m_pProduct;  //保持一个产品对象的指针
};

class Director{	//指挥者，负责建造产品的流程
public:
	void Construct(Builder* pBuilder);//根据传入的产品对象，构建具体产品
};