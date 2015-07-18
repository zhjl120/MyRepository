#include <wtypes.h>

class CashSuper3{
public:
	CashSuper3();
	virtual ~CashSuper3();

public:
	virtual float  AcceptCash(float fMoney);
};


class CashNormal3 : public CashSuper3{
public:
	CashNormal3();
	~CashNormal3();

public:
	float AcceptCash(float fMoney);
};


class CashRebate3 : public CashSuper3{
public:
	CashRebate3(float fRebate);
	~CashRebate3();

public:
	float AcceptCash(float fMoney);

private:
	float m_fRebate;
};


class CashReturn3 : public CashSuper3{
public:
	CashReturn3(float fMoneyCondition, float fMoneyReturn);
	~CashReturn3();

public:
	float AcceptCash(float fMoney);

private:
	float m_fMoneyCondition;
	float m_fMoneyReturn;
};


class CashContext3{
public:
	CashContext3(DWORD dwType);
	~CashContext3();

public:
	float GetTotalPrices(float fMoney);
	void Release();

private:
	CashSuper3* m_CashSuper;
};
