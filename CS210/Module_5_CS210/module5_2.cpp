
// ==============================================
// SNHU - CS210 Module 5-2 Homework  
// Author: David Neff  
// Date: 02/08/2025  
// ==============================================  
// Description:  
// Opens file to read temperature in fahrenheit - requires space seperated file with string city double temperature 
// Converts to celsius and outputs to an output file     
// ==============================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream inFS;   // Input file stream
   ofstream outFS; // Output file stream
   string city;     // File data
   double temperatureF; //double to hold temperature in F
   double temperatureC; //double to hold temperature in C
   

   //Create or opening output file
   outFS.open("CelsiusTemperature.txt");
   // Opening input file
   inFS.open("FahrenheitTemperature.txt");

    //make sure input file is good else return 1
   if (!inFS.is_open()) {
      cout << "Error opening input file." << endl;
      return 1;
   }
    //make sure output file is good else return 1
      if (!outFS.is_open()) {
      cout << "Could not open output file " << endl;
      return 1;
   }

   inFS >> city; //read in first city string
   inFS >> temperatureF; //read in temperature double (even though it comes in as int, i figure if we do more math we should have it as double)
   while (!inFS.fail()) {
    temperatureC = (temperatureF-32)*(5.0/9); //convert to Celsius
    outFS << city << " " << temperatureC << endl;; //format and send to output file
    inFS >> city; //read in next string
    inFS >> temperatureF; //read in next double
   }


   // Close both in and out
   inFS.close();
   outFS.close();

   return 0;
}
