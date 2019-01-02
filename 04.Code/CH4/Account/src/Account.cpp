#include "Account.h"
#include <iostream>
#include <sstream>
using namespace std;

double Account::interestRate = initRate();
int Account::nAccount = 0;

Account::Account(double t) : amount(t)
{
    nAccount++;
    stringstream    ss;
    ss << nAccount;
    ss >> owner;
    cout << nAccount << " is be constructed." << endl;
}

Account::Account(const Account& a)
{
    owner = a.owner;
    amount = a.amount;
    cout << ++nAccount << " is be copy constructed." << endl;
}

Account::Account(istream& is)
{
    is >> owner;
    is >> amount;
    cout << ++nAccount << " is be constructed." << endl;
}

Account::~Account()
{
    //dtor
}
void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::initRate()
{
    return 0.0005f;
}
