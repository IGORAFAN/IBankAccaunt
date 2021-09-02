#pragma once
#include <cstdint>

class CreditCard
{
public:
	CreditCard();
	uint64_t GetCreditBalance() const;
	uint64_t GetMainBalance() const;
	bool WithdrowMainBalance(uint64_t amount);
	bool WithdrowCreditBalance(uint64_t amount);
	bool GetCredit(uint64_t amount);
	void PutToMainBalance(uint64_t amount);
	void PutToCreditBalance(uint64_t amount);

private:
	void SetCreditLimit();

private:
	const uint32_t m_creditRatio = 25; //%
	uint64_t m_creditLimit;
	uint64_t m_mainBalance_UAH;
	uint64_t m_creditBalance_UAH;
};
