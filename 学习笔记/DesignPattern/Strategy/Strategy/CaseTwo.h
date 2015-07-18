#include <wtypes.h>

class CashSuper2{
public:
	CashSuper2();
	virtual ~CashSuper2();

public:
	virtual float  AcceptCash(float fMoney);
};


class CashNormal2 : public CashSuper2{
public:
	CashNormal2();
	~CashNormal2();

public:
	float AcceptCash(float fMoney);
};


class CashRebate2 : public CashSuper2{
public:
	CashRebate2(float fRebate);
	~CashRebate2();

public:
	float AcceptCash(float fMoney);

private:
	float m_fRebate;
};


class CashReturn2 : public CashSuper2{
public:
	CashReturn2(float fMoneyCondition, float fMoneyReturn);
	~CashReturn2();

public:
	float AcceptCash(float fMoney);

private:
	float m_fMoneyCondition;
	float m_fMoneyReturn;
};


class CashContext{
public:
	CashContext(CashSuper2* cs);
	~CashContext();

public:
	float GetTotalPrices(float fMoney);
	void Release();

private:
	CashSuper2* m_CashSuper;
};
