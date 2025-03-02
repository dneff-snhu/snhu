#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// Example function declarations
int add(int a, int b);
std::string greet(const std::string& name);
void testFunctions();

int main() {
    std::cout << "Function Development Sandbox\n";
    std::cout << "============================\n";

    testFunctions(); // Call function test cases

    return 0;
}

// Example function definitions
int add(int a, int b) {
    return a + b;
}

std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}


void printDetails(int years, double balance, double interest){
    cout << years << " : " << balance << " : " << interest << endl;

}
/* double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
  // you may wish to change this function when you bring it into your program
  // for now please get it to work here as specified
  double balance = initialInvestment;
  double interest = 0;
  for(int n = 1; n <= numberOfYears; ++n){
    balance = initialInvestment*pow((1+(interestRate/1200)),(12*n));
    interest = balance - initialInvestment;
    printDetails(n, balance, interest);
  }
  return balance;
} */

double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
  // you may wish to change this function when you bring it into your program
  // for now please get it to work here as specified
  double balance = initialInvestment;
  double interest = 0;
  for(int n = 1; n <= numberOfYears; ++n){
    for(int m = 0; m < 12; ++m){
        balance = balance*(1+(interestRate/1200));
        interest = balance - initialInvestment;
    }
    printDetails(n, balance, interest);
  }
  return balance;
}
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears){

  double balance = initialInvestment;
  double lastBalance = initialInvestment;
  double interest = 0;
  for(int n = 1; n <= numberOfYears; ++n){
    for(int m = 0; m < 12; ++m){
        balance = balance*(1+(interestRate/1200))+monthlyDeposit;
        interest = balance-monthlyDeposit - lastBalance;
        lastBalance = balance;
    }
    printDetails(n, balance, interest);
  }
  return balance;

}
// Function to test developed functions
void testFunctions() {
    balanceWithMonthlyDeposit(100,10,10,4);
}