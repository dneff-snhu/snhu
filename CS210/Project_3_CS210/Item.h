#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;
class Item {
private:
    string name;
    int quantity;
    int length;

public:
    //constructors
    Item();
    Item(string itemName, int itemQuantity);
    //setters
    void setName(string itemName);
    void setQuantity(int itemQuantity);
    //getters
    int getLength();
    string getName();
    int getQuantity();
    //mutators
    void incrementQuantity();
    void print();
    void histogram();
};

#endif // ITEM_H
