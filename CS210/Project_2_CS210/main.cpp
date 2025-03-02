#include <iostream>
#include "Investment.h"

using namespace std;

int main() {

    double initialInvestment;
    double annualInterestRate;
    double investmentTerm; 
    double monthlyDeposit;
    //instance of Invesment class
    Investment myInvestment(initialInvestment, annualInterestRate, investmentTerm, monthlyDeposit);
    //prompt user for investment details
    cout << "Initial Investment: $";
    cin >> initialInvestment;
    myInvestment.setInvestment(initialInvestment);
    myInvestment.setBalance(initialInvestment); 
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    myInvestment.setDeposit(monthlyDeposit);
    cout << "Annual Interest Rate: ";
    cin >> annualInterestRate;
    myInvestment.setApr(annualInterestRate);
    cout << "Investment Term: ";
    cin >> investmentTerm;
    myInvestment.setTerm(investmentTerm);
    cout << "----------------------------- ----" << endl;
    //this runs the calculation without monthly deposit
    myInvestment.printStatement(false);
    //this runs the calculation with monthly deposit
    myInvestment.printStatement(true);
    return 0;
}
