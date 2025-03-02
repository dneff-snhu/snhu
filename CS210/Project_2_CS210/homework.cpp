#include <string>
#include <iostream>

using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
      try{
      cin >> age;
      cout << inputName << " " << (age + 1) << endl;
   }
      catch (ios_base::failure& excpt) {
         cout << "t" << endl;
         cin.clear();
      }
      catch (...) {
         cout << "x" << endl;
         cin.clear();
      }
      cin >> inputName;
   }
   return 0;
}