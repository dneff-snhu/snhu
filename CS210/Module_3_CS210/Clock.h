//header file for the Clock class for Chada Project One
#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
using namespace std;
class Clock{

//Chada clock fields
private:
    string clockType;
    int numSeconds = 0;
    int numMinutes = 0;
    int numHours = 0;

public:

    //Here is a constructor
    Clock(string clkType);
    //setters!
    void setSecond(int s);
    void setMinute(int m);
    void setHour(int h);
    void setType(string clockType);


    //getters!
    int getSecond();
    int getHour();
    int getMinute();
    string getType();

// mutations
    void addOneSecond();
    void addOneMinute();
    void addOneHour();

};

#endif  