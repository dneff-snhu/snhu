double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
  // you may wish to change this function when you bring it into your program
  // for now please get it to work here as specified
  double balance;
  double interest;
  for(int n = 0; n < numberOfYears; ++n){
    balance = initialInvestment*pow((1+(interestRate/100)/12),(12*n));
    //interest = initialInvestment*(pow((1+(interestRate/100)/12),(12*n))-pow((1+(interestRate/100)/12),(12*n-1)));
    interest = balance - initialInvestment;
    printDetails(n, balance, interest);
  }
  return balance;