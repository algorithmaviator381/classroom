#ifndef PO_H_
#define PO_H_

#include "oc.h"
#include <iostream>

using namespace std;

struct Node {
public:
  Order order;
  Node *next;
};

class OrderLinkedList {
public:
  Node *head, *tail;
  int size;
  int results = 0;
  string modifyMode;

  OrderLinkedList() : size(0), head(NULL){};

  void insertAtEnd(string productName, double price, int quantity,
                   string customerName) {
    Node *newNode = new Node;
    int id = 0;

    // Inserting into empty list
    if (tail == NULL) {
      id = 1;
      head = tail = newNode;
    } else {
      id = tail->order.id + 1;
      tail->next = newNode;
      tail = newNode;
    }

    newNode->order = Order(id, productName, price, quantity, customerName);
    newNode->next = nullptr;
    size++;
  }

  void display() {
    if (size == 0) {
      cout << "List is empty!";
    } else {
      Node *curr = head;
      cout << "ID \t Product Name \t Price \t Quantity \t Customer Name"
           << endl;
      cout << "````````````````````````````````````````````````````````````````"
              "``\n";
      while (curr != nullptr) {
        curr->order.displayAll();
        curr = curr->next;
      }
    }

    cout << endl;
    cout << "Total Items: " << size << endl;
  }

  int getSize() { return size; }

  void modifyOrder(int id, string name) {
    Node *curr = head;
    if (modifyMode == "productName") {
      while (curr != NULL) {
        if (curr->order.id == id) {
          curr->order.productName = name;
          cout << "Order Successfully Updated" << endl;
          break;
        }
        curr = curr->next;
      }
    } else if (modifyMode == "customerName") {
      while (curr != NULL) {
        if (curr->order.id == id) {
          curr->order.customerName = name;
          cout << "Order Successfully Updated" << endl;
          break;
        }
        curr = curr->next;
      }
    }
    if (curr == NULL) {
      cout << "Order ID Not Found!";
    }
  }

  void modifyOrderPrice(int id, double price) {
    Node *curr = head;
    while (curr != NULL) {
      if (curr->order.id == id) {
        curr->order.price = price;
        cout << "Order Successfully Updated" << endl;
        break;
      }
      curr = curr->next;
    }
  }

  void modifyOrderQuantity(int id, double quantity) {
    Node *curr = head;
    while (curr != NULL) {
      if (curr->order.id == id) {
        curr->order.quantity = quantity;
        cout << "Order Successfully Updated" << endl;
        break;
      }
      curr = curr->next;
    }
  }

  void deleteOrder(int id) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL) {
      if (curr->order.id == id) {
        if (prev != NULL) {
          prev->next = curr->next;
        } else {
          head = curr->next;
        }
        delete curr;
        cout << "Deleted Successfully" << endl;
        size--;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    if (curr == NULL) {
      cout << "ID Not Found!";
    }
  }

  void searchOrderById(int id) { displayOrder(id); }

  void searchOrderByCustomerName(string customerName) {
    Node *curr = head;
    while (curr != NULL) {
      if (curr->order.customerName == customerName) {
        displayOrder(curr->order.id);
        results++;
      }
      curr = curr->next;
    }
    cout << "Total results found: " << results;
  }

  void searchOrderByProductName(string productName) {
    Node *curr = head;
    while (curr != NULL) {
      if (curr->order.productName == productName) {
        displayOrder(curr->order.id);
        results++;
      }
      curr = curr->next;
    }
    cout << "Total results found: " << results;
  }

  void searchOrderByPriceRange(double priceBottom, double priceTop) {
    Node *curr = head;
    while (curr != NULL) {
      if (curr->order.price >= priceBottom && curr->order.price <= priceTop) {
        curr->order.displayAll();
        results++;
      }
      curr = curr->next;
    }
    cout << "Total results found: " << results;
  }

  void displayOrder(int id) {
    Node *curr = head;

    while (curr != NULL) {
      if (curr->order.id == id) {
        cout << "\nProduct id           :" << curr->order.id;
        cout << "\nProduct Name         :" << curr->order.productName;
        cout << "\nProduct Prise        :" << curr->order.price;
        cout << "\nQuantity of order    :" << curr->order.quantity;
        cout << "\nCustomer Name        :" << curr->order.customerName;
        cout << "\n----------------------------------------------------\n\n";
      }
      curr = curr->next;
    }
  }

  int getTotalPrise() {
    int result = 0;

    Node *curr = head;
    while (curr != nullptr) {
      result += curr->order.price * curr->order.quantity;
      curr = curr->next;
    }

    return result;
  }

  void generateReport() {
    system("cls");
    cout << "********************* Purchase Order Report ********************* "
         << endl;
    cout << endl;
    display();
    Node *curr = head;
    double totalPrice = getTotalPrise();

    cout << "Total Price: " << totalPrice << " rupees" << endl;

    cout << endl;

    cout << "********************************************************* "
         << endl;
  }
};

OrderLinkedList orderLinkedList;

#endif