#pragma once
#include "CreditCard.h"
#include <string>

class IBank
{
public:
	virtual ~IBank() {}
	virtual CreditCard *GetAllCreditCardsByUserId(const std::string &userID) const = 0;
};