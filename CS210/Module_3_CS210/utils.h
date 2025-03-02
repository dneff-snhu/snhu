#ifndef UTILS_H
#define UTILS_H

#include "Item.h"
#include <vector>
#include <string>

using namespace std;

namespace Utils {
    void printItemList(const vector<Item>& items);
    Item findItemByName(const vector<Item>& items, const string& name);
    int getTotalQuantity(const vector<Item>& items);
}

#endif // UTILS_H
