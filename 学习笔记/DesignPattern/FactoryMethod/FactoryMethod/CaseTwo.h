#pragma  once

class OperationBase2 //抽象基类
{
public: 
	OperationBase2();
	virtual ~OperationBase2();

public:
	virtual float GetResult();

public:
	void SetNum1(float fNum1);
	void SetNum2(float fNum2);

	void Release();

protected:
	float m_fNum1;
	float m_fNum2;
};


class OperationAdd2 : public OperationBase2 //具体实现类
{
public:
	float GetResult();
};

class OperationSub2 : public OperationBase2
{
public:
	float GetResult();
};

class OperationMul2 : public OperationBase2
{
public:
	float GetResult();
};

class OperationDiv2 : public OperationBase2
{
public:
	float GetResult();
};


class OperationFactory2  //工厂类
{
public:
	virtual OperationBase2* CreateOperation() = 0;  //工厂抽象接口
};


class AddFactory : public OperationFactory2 //具体工厂类
{
public:
	OperationBase2* CreateOperation();
};

class SubFactory : public OperationFactory2
{
public:
	OperationBase2* CreateOperation();
};

class MulFactory : public OperationFactory2
{
public:
	OperationBase2* CreateOperation();
};

class DivFactory : public OperationFactory2
{
public:
	OperationBase2* CreateOperation();
};