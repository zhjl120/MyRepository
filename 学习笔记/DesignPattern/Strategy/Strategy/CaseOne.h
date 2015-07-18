#include <wtypes.h>

class CashSuper1{
public:
	CashSuper1();
	virtual ~CashSuper1();

public:
	virtual float  AcceptCash(float fMoney);
};


class CashNormal1 : public CashSuper1{
public:
	CashNormal1();
	~CashNormal1();

public:
	float AcceptCash(float fMoney);
};


class CashRebate1 : public CashSuper1{
public:
	CashRebate1(float fRebate);
	~CashRebate1();

public:
	float AcceptCash(float fMoney);

private:
	float m_fRebate;
};


class CashReturn1 : public CashSuper1{
public:
	CashReturn1(float fMoneyCondition, float fMoneyReturn);
	~CashReturn1();

public:
	float AcceptCash(float fMoney);

private:
	float m_fMoneyCondition;
	float m_fMoneyReturn;
};


class CashFactory{
public:
	CashFactory();
	~CashFactory();

public:
	static CashSuper1* CreateCashAccept(DWORD dwType);
	void Release();
};