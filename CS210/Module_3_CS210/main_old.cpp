#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Clock.h"
using namespace std;
//Turns integers into 2 digit strings for clock output
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
//creates a repeating string of character c
string nCharString(size_t n, char c) {
    return string(n, c);
}
//sets 24-hour clock format
string formatTime24(unsigned int h, unsigned int m, unsigned int s){
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}
//sets 12 hour clock format -  checks for am/pm meridiem
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
//prints out the menu per requirements
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
    cout << nCharString(width,'*') << endl;
}
//displays both 12 hour and 24 hour clock in required format
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;
    cout << "*" << nCharString(6,' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*   ";
    cout << "*" << nCharString(6,' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout<<endl;
    cout << "*" << nCharString(6,' ') << formatTime12(h,m,s) << nCharString(7, ' ') << "*   ";
    cout << "*" << nCharString(8,' ') << formatTime24(h,m,s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;
}
//loops to process user input
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

  int main() {
    //holds menu options
    char *clockOptions[] = {
        (char *)"Add One Hour",
        (char *)"Add One Minute",
        (char *)"Add One Second",
        (char *)"Exit Program"
    };
    //string to hold initial time input
    string startTime;
    Clock chadaClock("any");
    //TODO need user input error handling
    cout <<"Enter start time - hh:mm:ss ";
    cin >> startTime;
    //breaks down user input into 3 integers - this is sketchy but works for now
    chadaClock.setHour(stoi(startTime.substr(0,2)));
    chadaClock.setMinute(stoi(startTime.substr(3,2)));
    chadaClock.setSecond(stoi(startTime.substr(6,2)));

    int userChoice;
    //loops for the user menu
    while(userChoice != 4){
        //show menu
        printMenu(clockOptions, 4, 30);
        //prompt for choice
        userChoice = getMenuChoice(4);
        //switch for clock options
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
    //displays the clock
    displayClocks(chadaClock.getHour(), chadaClock.getMinute(), chadaClock.getSecond());
}   
    return 0;
}