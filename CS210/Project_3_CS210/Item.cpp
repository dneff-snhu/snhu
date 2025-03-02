#include "Item.h"
#include <iostream>
#include <iomanip>
//default constructor
Item::Item(){
    name = "null";
    quantity = 1;
    length = 0;
}
//constructor with parameters
Item::Item(string itemName, int itemQuantity){
    name = itemName;
    quantity = itemQuantity;
}
//sets item name and logs its length
void Item::setName(string itemName){
    name = itemName;
    length = name.length();
}
//change item quanitity
void Item::setQuantity(int itemQuantity){
    quantity = itemQuantity;
}
//returns the length of the name string
int Item::getLength(){
    return length;
}
//returns the name of the item
string Item::getName(){
    return name;
}
//returns the quanitity
int  Item::getQuantity(){
    return quantity;
}
//increase quanitity by one
void Item::incrementQuantity(){
    ++quantity;
}
//prints  right justified name and quanitity
void Item::print(){
    cout << setw(15) << name << " " << quantity << endl;
}
//prints right justified  name and a char for each quanitity
void Item::histogram(){
    cout << setw(15) << name << " " << string(quantity, '*') << endl;
}