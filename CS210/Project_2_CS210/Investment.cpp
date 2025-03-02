#include "Investment.h" 
#include <string>
#include <iomanip>

//constructor 
Investment::Investment(double investment, double apr, double term, double deposit){
    this->investment = (investment >= 0) ? investment:0;
    this->balance = investment;
    this->apr = ((apr >= 0) && (apr < 100)) ? apr: 0;
    this->term = (term > 0) ? term : 0;
    this->deposit = (deposit > 0) ? deposit : 0;
}
//Investment setters
void Investment::setInvestment(double investment){
    this->investment = investment;
}

void Investment::setBalance(double balance){
    this->balance = balance;
}

void Investment::setApr(double apr){
    this->apr = apr;
}

void Investment::setTerm(double term){
    this->term = term;
}
void Investment::setDeposit(double deposit){
    this->deposit = deposit;
}

//Getter for investment fields
double Investment::getInvestment(){
    return investment;
}

double Investment::getBalance(){
    return balance;
}

double Investment::getApr(){
    return apr;
}
double Investment::getTerm(){
    return term;
}
double Investment::getDeposit(){
    return deposit;
}
//mutators to add one increment Investment integers

void Investment::printDetails(int years, double balance, double interest) {
    //one-line print to loop through years of calculation                      
    cout <<  setw(5) << right << years
    << setw(20) << right << "$"<< fixed << setprecision(2) << balance
    << setw(20) << right << "$"<< fixed << setprecision(2) << interest << endl;
}
//didn't use it but i'm scared to remove it
void Investment::addDeposit(double deposit){
    balance = balance + deposit;
}

void Investment::calcWODeposit() {
  //initialize the balance and interest variables
  this->setBalance(investment);
  double totalInterest = 0;
  double interest = 0;
  //outer loop for the term in years 
  for(int n = 1; n <=  term; ++n){
    //inner loop for the monthly interest
    for(int m = 0; m < 12; ++m){
        interest = balance*(apr/1200);
        balance = balance + interest;
        totalInterest = totalInterest + interest;
    }
    //print the one-line results
    printDetails(n, balance, totalInterest);
    totalInterest = 0;
  }
}

void Investment::calcWithDeposit() {
    //initialize the balance and interest variables
  this->setBalance(investment);
  double totalInterest = 0;
  double interest = 0;
  //outer loop for the term in years 
  for(int n = 1; n <=  term; ++n){
    //inner loop for the monthly interes
    for(int m = 0; m < 12; ++m){
        balance = balance + deposit;
        interest = balance*(apr/1200);
        balance = balance + interest;
        totalInterest = totalInterest + interest;
    }
     //print the one-line results
    printDetails(n, balance, totalInterest);
    totalInterest = 0;
  }
}
//function to print multiple char
string Investment::nCharString(size_t n, char c) {
    return string(n, c);
}
//function to print all stats with a bool whether to include monthly deposits
void Investment::printStatement(bool select) {
    if(!select){
        cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
        cout << nCharString(60,'=') << endl;
        cout << setw(10) << "Year"  << setw(30) <<  "Year End Balance"<<  setw(30) << "Year End Earned Interest" << endl;
        calcWODeposit();
        cout << nCharString(60, '-');
        cout << endl;
        cout << nCharString(60,'*') << endl;
    }
    else{
        cout << "Balance and Interest With Additional Monthly Deposits" << endl;
        cout << nCharString(60,'=') << endl;
        cout << setw(10) << "Year"  << setw(30) <<  "Year End Balance"<<  setw(30) << "Year End Earned Interest" << endl;
        calcWithDeposit();
        cout << nCharString(60, '-');
        cout << endl;
        cout << nCharString(60,'*') << endl;
    }
}

