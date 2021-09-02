#include "MyBank.h"
#include "MyAccount.h"

int main()
{
	CreditCard *firstCreditCard = new CreditCard;
	MyAccount *firstAccount = new MyAccount("321415");
	MyBank *mainBank = new MyBank;
	mainBank->CreateAccount(firstAccount);
	firstAccount->CreateNewCreditCard(firstCreditCard);
	firstCreditCard->PutToMainBalance(100);
	uint64_t result = firstAccount->PutToDeposite(100, 4);

	return 0;
}