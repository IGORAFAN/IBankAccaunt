#pragma once
#include <cstdint>

enum Currency
{
	USD = 1,
	UAH = 2
};

class IAccount
{
public:
	virtual ~IAccount() {}
	virtual Currency GetCurrency() const = 0; // Currency is the enum with values USD, UAH
	virtual uint64_t GetCreditBalance() const = 0;
	virtual uint64_t GetMainBalance() const = 0; // your money in the card
	virtual void Withdrow(uint64_t amount) = 0;
	virtual bool GetCredit(uint64_t amount) = 0; // you can ask the bank for the credit
};