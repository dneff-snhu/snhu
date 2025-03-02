#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream inFS;   // Input file stream
   string fileNum;     // File data

   // Open file
   cout << "Opening file myfile.txt." << endl;
   inFS.open("myoutfile.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file myfile.txt." << endl;
      return 1;
   }

   // Print read numbers to output
   cout << "Reading and printing numbers." << endl;

   inFS >> fileNum;
   while (!inFS.fail()) {
      cout << "Item: " << fileNum << endl;
      inFS >> fileNum;
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file myfile.txt." << endl;

   // Done with file, so close it
   inFS.close();

   return 0;
}

/* #include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream outFS; // Output file stream

   // Open file
   outFS.open("myoutfile.txt");

   if (!outFS.is_open()) {
      cout << "Could not open file myoutfile.txt." << endl;
      return 1;
   }

   // Write to file
   outFS << "Hello" << endl;
   outFS << "1 2 3" << endl;

   // Done with file, so close
   outFS.close();

   return 0;
} */