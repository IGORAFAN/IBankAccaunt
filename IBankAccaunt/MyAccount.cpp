#include "MyAccount.h"
#include <ctime>

MyAccount::MyAccount(const std::string &clientID)
    : m_clientID(clientID), m_countCreditCards(0)
{
}

const std::string &MyAccount::GetClientID()
{
    return m_clientID;
}

CreditCard *MyAccount::GetCreditCardByNumber(uint32_t number)
{
    return m_creditCards[number];
}

MyAccount::~MyAccount()
{
    for (size_t iter = 0; iter < 5; ++iter)
    {
        if (m_creditCards[iter])
        {
            delete m_creditCards[iter];
        }
    }
}

uint64_t MyAccount::PutToDeposite(uint64_t amount, uint32_t monthCount)
{
    uint64_t result = (((amount / 100) * m_depositeRatio) / 12) * monthCount;
    return result;
}

bool MyAccount::CreateNewCreditCard(CreditCard *newCard)
{
    if (m_countCreditCards >= 5)
    {
        return false;
    }
    else
    {
        m_creditCards[m_countCreditCards] = newCard;
        ++m_countCreditCards;
        return true;
    }
}

bool MyAccount::DeleteCreditCard(uint32_t number)
{
    if (!m_creditCards[number])
    {
        return false;
    }
    else
    {
        delete m_creditCards[number];
        m_creditCards[number] = nullptr;
        --m_countCreditCards;
        return true;
    }
}

CreditCard *MyAccount::GetAllCreditsCard()
{
    return m_creditCards[0];
}
