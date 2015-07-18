#pragma  once

class OperationBase{
public: 
	OperationBase();
	virtual ~OperationBase();

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

class OperationAdd : public OperationBase{
public:
	float GetResult();
};

class OperationSub : public OperationBase{
public:
	float GetResult();
};

class OperationMul : public OperationBase{
public:
	float GetResult();
};

class OperationDiv : public OperationBase{
public:
	float GetResult();
};