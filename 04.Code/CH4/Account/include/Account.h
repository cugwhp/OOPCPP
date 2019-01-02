#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Account
{
public:
    Account(double t=0.0f);
    Account(const Account& a);
    explicit Account(istream& is);
    virtual ~Account();

    inline double calculate() {amount += amount*interestRate; return amount;}
    static double rate() {return interestRate;}
    static void rate(double);

//    static constexpr double frate = 20.0f;
//    static constexpr int vecSize = 20;
//    static std::vector<double> vec(vecSize);
protected:
    static int  nAccount;
private:
    std::string owner;
    double      amount;
    static double interestRate;
    static double initRate();
};

#endif // ACCOUNT_H
