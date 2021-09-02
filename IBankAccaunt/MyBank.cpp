#include "MyBank.h"

MyBank::MyBank()
	: m_clientCount(0)
{
}

MyBank::~MyBank()
{
	for (size_t iter = 0; iter < m_clientCount; ++iter)
	{
		if (m_clients[iter])
		{
			delete m_clients[iter];
		}
	}
}

void MyBank::CreateAccount(MyAccount *newClient)
{
	m_clients[m_clientCount] = newClient;
	++m_clientCount;
}

void MyBank::DeleteAccount(const std::string &clientID)
{
	for (size_t iter = 0; iter < m_clientCount; ++iter)
	{
		if (m_clients[iter]->GetClientID() == clientID)
		{
			delete m_clients[iter];
			m_clients[iter] = nullptr;
			--m_clientCount;
			break;
		}
	}
}

CreditCard *MyBank::GetAllCreditCardsByUserId(const std::string &userID) const
{
	for (size_t iter = 0; iter < m_maxClient; ++iter)
	{
		if (m_clients[iter]->GetClientID() == userID)
		{
			return m_clients[iter]->GetAllCreditsCard();
		}
	}
	return nullptr;
}