//header file for the Clock class for Chada Project One
#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <iostream>
#include <string>
using namespace std;
class Investment{

//class fields
private:
    char printOptions;
    double investment;
    double balance;
    double apr;
    double term;
    double interest;
    double deposit;

public:

    //Here is a constructor
    Investment(double investment, double apr, double term, double deposit);
    //setters!
    void setInvestment(double investment);
    void setBalance(double balance);
    void setApr(double apr);
    void setTerm(double term);
    void setDeposit(double deposit);


    //getters!
    double getInvestment();
    double getBalance();
    double getApr();
    double getTerm();
    double getDeposit();

// mutations
    void addDeposit(double deposit);
    void calcWithDeposit();
    void calcWODeposit();
    void printStatement(bool select);
    void printDetails(int years, double balance, double interest);
    string nCharString(size_t n, char c);
};

#endif  