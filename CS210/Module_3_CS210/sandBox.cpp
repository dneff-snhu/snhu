#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Clock.h"
using namespace std;


void testFunctions();
int tryClock();
string startTime;
unsigned int getMenuChoice(unsigned int maxChoice);
void printMenu(char * strings[], unsigned int numStrings, unsigned char width);
void displayClocks(unsigned int h, unsigned int m, unsigned int s);

int main() {
    Clock chadaClock("24-hour");
    cout <<"Enter start time - hh:mm:ss ";
    cin >> startTime;

    chadaClock.setHour(stoi(startTime.substr(0,2)));
    chadaClock.setHour(stoi(startTime.substr(3,2)));
    chadaClock.setHour(stoi(startTime.substr(6,2)));

    int userChoice;
    while(userChoice != 4){
        userChoice = getMenuChoice(4);
        switch (userChoice) {
        case 1:
            chadaClock.addOneHour();
            break;
        case 2:
            chadaClock.addOneMinute();
            break;
        case 3:
            chadaClock.addOneSecond();
            break;
        default:
            break;
    }
    displayClocks(chadaClock.getHour(), chadaClock.getMinute(), chadaClock.getSecond());
}   
    return 0;
}

string twoDigitString(unsigned int n) {
   string stringDigits;
   if(n>=0 && n<10){
      stringDigits = to_string(n);
      stringDigits = "0"+stringDigits;
   }
   else{
      stringDigits = to_string(n);
   }
  return stringDigits;
}

string nCharString(size_t n, char c) {
    return string(n, c);
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s){
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s){
    string meridiem = " A M";

    if(h>11){
        meridiem = " P M";
    }
    h = h % 12;
    if(h==0){
        h=12;
    }
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s)+meridiem;
}

void printMenu(char * strings[], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width,'*');
    cout << endl;
    for (size_t n = 0; n < numStrings; ++n){
        cout << "* " << n+1 << " - " << strings[n];
        cout << nCharString((width - strlen(strings[n])-7),' ');
        cout << '*' << endl;
        if (n<numStrings-1){
            cout << endl;
        }
    }
    cout << nCharString(width,'*');
}

int tryClock(){
    // Create a Clock object (12-hour or 24-hour format)
    Clock myClock("24-hour");

    // Set initial time to 23:59:58
    myClock.setHour(22);
    myClock.setMinute(59);
    myClock.setSecond(58);

    // Display initial time
    cout << "Initial Time: " 
         << myClock.getHour() << ":" 
         << myClock.getMinute() << ":" 
         << myClock.getSecond() << endl;

    // Add seconds to test overflow
    myClock.addOneSecond();
    cout << "After 1 Second: " 
         << myClock.getHour() << ":" 
         << myClock.getMinute() << ":" 
         << myClock.getSecond() << endl;

    myClock.addOneSecond();
    cout << "After Another Second: " 
         << myClock.getHour() << ":" 
         << myClock.getMinute() << ":" 
         << myClock.getSecond() << endl;

    return 0;
}


void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;
    cout << "*" << nCharString(6,' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*   ";
    cout << "*" << nCharString(6,' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout<<endl;
    cout << "*" << nCharString(6,' ') << formatTime12(h,m,s) << nCharString(7, ' ') << "*   ";
    cout << "*" << nCharString(8,' ') << formatTime24(h,m,s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;
}

void testFunctions() {
    cout << "Hello World!";
}

unsigned int getMenuChoice(unsigned int maxChoice){
  int choice;
  while(true){
    cout << "Enter Choice: ";
    cin >> choice;
    if((choice > 0) && (choice <= maxChoice) ){
        return choice;
    }
    else {
      continue;
    }
    }
  }