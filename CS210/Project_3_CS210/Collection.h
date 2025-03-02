#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
#include "Item.h"
#include <vector>

using namespace std;
class Collection {
private:
    vector<Item> items;
    string name;

public:
    //constructors
    Collection();
    Collection(string CollectionName);
    //setters
    void setName(string CollectionName);
    //getters
    string getName();
    int getQuantity(string itemName);
    //check for item in vector
    pair<bool, int> foundItem(string itemName);
    //adds to the vector
    void addItem(Item item);
    //finds number of items in the collection
    int countItems();
    // turns string to lowercase for comparison 
    string lowerCase(string itemName);
    //add to quantity
    void incrementQuantity(string itemName);
    //display methods
    void printAll();
    void printItem(string itemName);
    void printHistogram();

};

#endif // Collection_H
