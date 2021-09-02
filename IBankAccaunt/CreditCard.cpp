#include "CreditCard.h"

CreditCard::CreditCard()
	: m_creditLimit(0), m_mainBalance_UAH(0), m_creditBalance_UAH(0)
{
}

uint64_t CreditCard::GetCreditBalance() const{
	return m_creditBalance_UAH;
}

uint64_t CreditCard::GetMainBalance() const {
	return m_mainBalance_UAH;
}

bool CreditCard::WithdrowMainBalance(uint64_t amount){
	if (amount > m_mainBalance_UAH) {
		return false;
	}
	else {
		m_mainBalance_UAH += amount;
		return true;
	}
}

bool CreditCard::WithdrowCreditBalance(uint64_t amount){
	if (amount > m_creditBalance_UAH) {
		return false;
	}
	else {
		m_creditBalance_UAH += amount;
		return true;
	};
}

bool CreditCard::GetCredit(uint64_t amount) {
	SetCreditLimit();
	if (amount > m_creditLimit) {
		return false;
	}
	else {
		m_creditBalance_UAH += amount;
		return true;
	}
}

void CreditCard::PutToMainBalance(uint64_t amount){
	m_mainBalance_UAH += amount;
}

void CreditCard::PutToCreditBalance(uint64_t amount){
	m_creditBalance_UAH += amount;
}

void CreditCard::SetCreditLimit() {
	m_creditLimit = (m_mainBalance_UAH / 100) * m_creditRatio;
}
