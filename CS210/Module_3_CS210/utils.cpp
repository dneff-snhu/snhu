#include "utils.h"
#include <iostream>

namespace Utils {

    void printItemList(const vector<Item>& items) {
        for (const auto& item : items) {
            item.print();
        }
    }

    Item findItemByName(const vector<Item>& items, const string& name) {
        for (const auto& item : items) {
            if (item.getName() == name) {
                return item;
            }
        }
        return Item("Not Found", 0);
    }

    int getTotalQuantity(const vector<Item>& items) {
        int total = 0;
        for (const auto& item : items) {
            total += item.getQuantity();
        }
        return total;
    }

}
