#include "Clock.h" 
#include <string>

//Define constructor
Clock::Clock(string cType){
    clockType = cType;
}

//Setting clock type (12 or 24)
//TODO get rid of this field - didn't actually need a type and don't use it for anything
void Clock::setType(string cType){
    clockType = cType;
}
//Setting clock integers
void Clock::setSecond(int s){
    numSeconds = s;
}

void Clock::setMinute(int m){
    numMinutes = m;
}

void Clock::setHour(int h){
    numHours = h;
}

//Getter fields to return clockType string and all the clock numbers
string Clock::getType(){
    return clockType;
}

int Clock::getSecond(){
    return numSeconds;
}

int Clock::getMinute(){
    return numMinutes;
}
int Clock::getHour(){
    return numHours;
}
//mutators to add one increment clock integers
void Clock::addOneHour(){
    if(getHour() == 23){
        setHour(0);
    }
    else{
      setHour(getHour()+1);
    }
}

void Clock::addOneMinute(){
    if(getMinute() == 59){
        addOneHour();
        setMinute(0);
    }
    else{
      setMinute(getMinute()+1);
}
}

void Clock::addOneSecond(){
    if(getSecond() == 59){
        addOneMinute();
        setSecond(0);
    }
    else{
      setSecond(getSecond()+1);
    }
}