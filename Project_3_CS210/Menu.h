#ifndef MENU_H
#define MENU_H
#include <string>
#include "Item.h"
#include <vector>

using namespace std;
class Menu {
private:
    vector<string> menuOptions;
    string name;

public:
//constructors
    Menu();
    Menu(string menuName);
    //setter
    void setName(string menuName);
    //adds a menu option to the menu list
    void addItem(string newOption);
    //gets menu name
    string getName();
    //prints the whole menu
    void printAll();
    //prints one menu option
    void printOption(int index);
    //adds a line of characters for asthetics
    void addLine(size_t n, char c);
    string nCharString(size_t n, char c);
    //asks user for menu selection
    int promptUser(string prompt, int numOptions);
};

#endif // Menu_H
