#include "Menu.h"
#include "Item.h"
#include <iostream>
#include <algorithm>

using namespace std;
// constructors
Menu::Menu(){
    name = "null";
}

Menu::Menu(string MenuName){
    name = MenuName;
}
//setter
void Menu::setName(string MenuName){
    name = MenuName;
}
//getter
string Menu::getName(){
    return name;
}
//add item tom menu
void Menu::addItem(string menuOption){
        //cout << "Pushing " << menuOption << endl;
        menuOptions.push_back(menuOption);
    }
//creates a decoration
string Menu::nCharString(size_t n, char c) {
        return string(n, c);
    }
//puts a line in the menu vector
void Menu::addLine(size_t n, char c){
    addItem(nCharString(n, c));
}
//prints all menu options
void Menu::printAll(){
    //cout << "Printing All for "<< menuOptions.size() << " options" << endl;
    for(size_t i = 0; i < menuOptions.size(); ++i){
        cout << menuOptions[i] << endl;
    }
}
//print single menu option
void Menu::printOption(int index){
    cout << menuOptions[index] << endl;
}
//returns int correspond to option #
int Menu::promptUser(string prompt, int numOptions){
    int selection;
    while (true){
    cout << prompt << ": ";
    //get user input
    try{
        cin >> selection;
        //error handling
        if(cin.fail()){
            throw invalid_argument("Invalid selection.");
        }
        if(selection < 1 || selection > numOptions){
            throw out_of_range("Invalid selection.");
        }
        return selection;
    }
    //error catch for logic erro
    catch(const invalid_argument &e){
       cout << e.what() << endl;
    }
    //catch range problem
    catch(const out_of_range &e){
        cout << e.what() << endl;
    }
    //clear errors
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');    
    }
}
