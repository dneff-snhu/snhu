#include "Collection.h"
#include "Item.h"
#include <iostream>
#include <algorithm>

using namespace std;
//Default constructor
Collection::Collection(){
    name = "null";
}
//Constructor with name
Collection::Collection(string CollectionName){
    name = CollectionName;
}

//Setter fields
void Collection::setName(string CollectionName){
    name = CollectionName;
}
//getter fields
string Collection::getName(){
    return name;
}

int  Collection::getQuantity(string itemName){
    //gets quantity with class method
    if(foundItem(itemName).first){
        return items[foundItem(itemName).second].getQuantity();    
    }
    else{
        return 0;
    }
}

//Mutators

//Function to change strings to lowercase so they aren't case sensitive
string Collection::lowerCase(string itemName){
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
    return itemName;
}
//function to check for an item and return a bool and it's index
pair<bool, int> Collection::foundItem(string itemName){
    for(size_t i = 0; i < items.size(); ++i){
        if(lowerCase(items[i].getName()) == lowerCase(itemName)){
               return {true, i};
        }
    }
    return {false, -1};
}

//+1 on an inventory item
void Collection::incrementQuantity(string itemName){
    if(foundItem(itemName).first){
        items[foundItem(itemName).second].setQuantity(1+items[foundItem(itemName).second].getQuantity());    
    }
}
//adds an object of class Item to the inventory vector or increment if the item already exists
void Collection::addItem(Item item){
    if (foundItem(item.getName()).first){
        incrementQuantity(item.getName());
    }
    else {
        items.push_back(item);
    }
}
//Display methods

//prints whole collection  name and quantity - calling Item print method
void Collection::printAll(){
    for(size_t i = 0; i < items.size(); ++i){
        items[i].print();
    }
}

//prints whole collection, name and a * for each unit - calling Item print method

void Collection::printHistogram(){
    for(size_t i = 0; i < items.size(); ++i){
        items[i].histogram();
    }
}
//prints a single item if found in collection
void Collection::printItem(string itemName){
    pair<bool, int> search = foundItem(itemName);
    if(search.first){
        items[search.second].print();    
    }
    else{
        cout << itemName << " 0" <<endl;
    }
}
