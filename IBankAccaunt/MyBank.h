#pragma once
#include "IBank.h"
#include "CreditCard.h"
#include "MyAccount.h"

class MyBank : public IBank
{
public:
	MyBank();
	~MyBank();
	void CreateAccount(MyAccount *newClient);
	void DeleteAccount(const std::string &clientID);
	CreditCard *GetAllCreditCardsByUserId(const std::string &userID) const override;

private:
	size_t m_clientCount;
	const size_t m_maxClient = 100;
	MyAccount *m_clients[100] = {nullptr};
};