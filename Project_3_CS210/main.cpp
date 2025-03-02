#include "Item.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Collection.h"

using namespace std;
//This function sets up the options menu vector
void setupMenu(Menu& myMenu){
    const int numOptions = 4;
    //an array to build the individual options
    string menuOptions[4] = {
        "1. Search Inventory",
        "2. Print List",
        "3. Print histogram",
        "4. Exit"
    };
    //line for decoration insert into vector
    myMenu.addLine(20,'-');
    //inserts the array  elements into a vector
    for(int n = 0; n<numOptions;++n){
        myMenu.addItem(menuOptions[n]);
    }
    //decoration
    myMenu.addLine(20,'-');
    }
//This function  opens file and pulls in each line
void loadData(Collection& collection){
    ifstream inFS;
    Item tempItem;
    string fileData; 
    //open file
    inFS.open("CS210_Project_Three_Input_File.txt");
    //error for file open
    if (!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return;
     }
     //filestream
     inFS >> fileData;
     //do until end of file
     while (!inFS.fail()) {
        //takes the string from the file and assigns a name to a temporaty Item object
        tempItem.setName(fileData);      
        //add that item to the collection. addItem() check for existing identical item and increments quanitity if already in the collection
        collection.addItem(tempItem);
        inFS >> fileData;
     }
     //message if file has a problem mid-stream
    if (!inFS.eof()) {
        cout << "Input failure before reaching end of file." << endl;
     } 
     //close file
    inFS.close();
}
int main() {
    int choice;
    string userInput;
    //Collection object houses inventory
    Collection myCollection("Shopping Cart");
    //load data fills the collection 
    loadData(myCollection);
    //instan ciate a Menu object
    Menu myMenu("Inventory Menu");
    //build the menu
    setupMenu(myMenu);
    
    //switch to manage m,enu selection
    while(choice != 4){
        //show menu
        myMenu.printAll();
        //menu method handles input  intergity
        choice = myMenu.promptUser("Make a selection",4);
        switch (choice){
            case 1: //single search. printItem(checks for the item in the collection)
                cout << "Enter an Item to Search the Inventory: ";
                cin >> userInput;
                myCollection.printItem(userInput);
                choice = 0;
                break;
            case 2://printAll shows the name and quanitity of all items in the vector
                myCollection.printAll();
                choice = 0;
                break;
            case 3://instead of quanitity this prints the quantity as a char per unit
                myCollection.printHistogram();
                choice = 0;
                break;
        }
    }
    return 0;
}
