#pragma once
//#include "IAccount.h"
#include "CreditCard.h"
#include <cstdint>
#include <string>

class MyAccount
{
public:
	MyAccount(const std::string &clientID);
	~MyAccount();
	//Currency GetCurrency() const;
	const std::string &GetClientID();
	CreditCard *GetCreditCardByNumber(uint32_t number);
	CreditCard *GetAllCreditsCard();
	uint64_t PutToDeposite(uint64_t amount, uint32_t monthCount);
	bool DeleteCreditCard(uint32_t number);
	bool CreateNewCreditCard(CreditCard *newCard);

private:
	std::string m_clientID;
	uint64_t m_depositeRatio = 18; //%
	size_t m_countCreditCards;
	CreditCard *m_creditCards[5] = {nullptr};
};