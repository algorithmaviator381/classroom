#ifndef ORDER_CLASS_H
#define ORDER_CLASS_H

#include <iostream>

using namespace std;

class Order {
public:
  int id;
  string productName;
  double price;
  int quantity;
  string customerName;

  Order() {}

  Order(int id, string productName, double price, int quantity,
        string customerName) {
    this->id = id;
    this->productName = productName;
    this->price = price;
    this->quantity = quantity;
    this->customerName = customerName;
  }

  void displayAll() {
    cout << id << " \t " << productName << " \t  " << price << "\t " << quantity
         << "\t\t " << customerName << "\t" << endl;
  }
};

#endif