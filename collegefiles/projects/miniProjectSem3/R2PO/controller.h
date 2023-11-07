#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <conio.h>
#include <iostream>
#include <string>

// #include "PO.h"
#include "login.h"
#include "purchaseOrder.h"

using namespace std;

string username, password;
string mode[] = {"product", "price", "Quantity", "customerName"};
string status[] = {"Processing", "Released", "Received", "Canceled"};

void menu() {
  system("cls");
  cout << "-----Purchase Order Management System-----" << endl;
  cout << "Please enter Username and Password to login." << endl;
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;
  cout << endl;
}

void loadData() {
  orderLinkedList.insertAtEnd("Office Desk", 250.00, 5, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Monitor", 300.00, 120, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Mouse  ", 300.00, 120, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Keyboard", 300.00, 120, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Office Chair", 150.00, 160, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Whiteboard", 100.00, 13, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Projector", 800.00, 5, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Desk Lamp", 40.00, 10, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Shelf  ", 120.00, 20, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Printer", 150.00, 8, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Printer Paper", 10.00, 50, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Scanner", 100.00, 12, "AISSMS IOIT, Pune");
  orderLinkedList.insertAtEnd("Marker  ", 8.00, 30, "AISSMS IOIT, Pune");
}

void portal() {
  system("cls");
  cout << endl;
  cout << "----------------------------------------------------------------"
       << endl;
  cout << "Welcome to R2PO CLI procurement application portal " << globalName
       << endl;
  cout << "----------------------------------------------------------------"
       << endl;
  cout << "\nPurchase Order summary: " << endl << endl;

  // Display Order List
  orderLinkedList.display();
  cout << "-------------------------------------------------" << endl;
  cout << endl;
}

void runAdmin() {
  portal();

  orderLinkedList.results = 0;
  int opt;

  cout << "1) Modify Order details" << endl;
  cout << "2) Search Order" << endl;
  cout << "3) Delete Order" << endl;
  cout << "4) Generate Report" << endl;

  cout << endl;
  cout << "0) Exit" << endl;

  cout << "-------------------------------------------------" << endl;
  cout << "> Choose: ";
  cin >> opt;

  switch (opt) {

  // Modify Order
  case 1: {
    portal();
    cout << "Please insert the ID of the Order to be modified." << endl;

    cout << endl;
    cout << "0) Back" << endl;

    cout << "-------------------------------------------------" << endl;
    cout << "> Input: ";
    int id;
    cin >> id;

    if (id == 0) {
      runAdmin();
    } else {
      system("cls");

      orderLinkedList.displayOrder(id);

      cout << "Please select what to modify." << endl;
      cout << endl;

      cout << "1) Product Name" << endl;
      cout << "2) Price" << endl;
      cout << "3) Quantity" << endl;
      cout << "4) Customer name" << endl;

      cout << endl;
      cout << "0) Back to main menu" << endl;

      cout << "--------------------------------------------------------"
           << endl;
      cout << "Your choice: ";
      cin >> opt;

      system("cls");

      switch (opt) {
      case 1: {
        string productName;
        orderLinkedList.modifyMode = "productName";

        cout << "Please insert new Product Name: " << endl;
        cin.ignore();
        getline(cin, productName);
        // cin>>productName;

        orderLinkedList.modifyOrder(id, productName);
        break;
      }
      case 2: {
        orderLinkedList.modifyMode = "price";
        cout << "Please insert new Price: " << endl;
        double price;
        cin >> price;

        if (price > 0) {
          orderLinkedList.modifyOrderPrice(id, price);
        } else {
          cout << "Invalid Price!";
        }

        break;
      }
      case 3: {
        cout << "Please insert the updated quantity of product:" << endl;
        int quantity;
        cin >> quantity;

        orderLinkedList.modifyOrderQuantity(id, quantity);

        break;
      }
      case 4: {
        orderLinkedList.modifyMode = "customerName";
        cout << "Please insert new customer Name:" << endl;
        string customerName;
        cin.ignore();
        getline(cin, customerName);

        orderLinkedList.modifyOrder(id, customerName);

        break;
      }
      case 0: {
        runAdmin();
        break;
      }
      default: {
        system("cls");
        cout << "\n--------------------------------------------" << endl;
        cout << "Please enter valid input. Press any key to proceed further...";
        getch();
        break;
      }
      }

      getch();
    }
    break;
  }

  // Search Order
  case 2: {
    portal();
    cout << "Please select what to search." << endl;

    cout << endl;

    cout << "1) ID" << endl;
    cout << "2) Product Name" << endl;
    cout << "3) Price" << endl;
    cout << "4) Customer Name" << endl;

    cout << endl;
    cout << "0) Back" << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "Your choice: ";
    cin >> opt;

    system("cls");

    switch (opt) {
    case 1: {
      cout << "Please insert ID to search:" << endl;
      int id;
      cin >> id;

      orderLinkedList.searchOrderById(id);
      getch();
      break;
    }
    case 2: {
      cout << "Please insert Product Name to search:" << endl;
      string productName;
      cin >> productName;

      orderLinkedList.searchOrderByProductName(productName);
      getch();
      break;
    }
    case 3: {
      cout << "Please insert Price range to search : " << endl;
      double priceBottom, priceTop;
      cout << "Enter bottom Price range: ";
      cin >> priceBottom;
      cout << "Enter top Price range: ";
      cin >> priceTop;

      orderLinkedList.searchOrderByPriceRange(priceBottom, priceTop);
      getch();
      break;
    }
    case 4: {
      cout << "Please insert Customer Name to search:" << endl;
      string customerName;
      cin >> customerName;

      orderLinkedList.searchOrderByCustomerName(customerName);
      getch();
      break;
    }
    case 0: {
      runAdmin();
      break;
    }
    default: {
      cout << "\n--------------------------------------------" << endl;
      cout << "> Thank You..." << endl;
      exit(0);
      break;
    }
    }
    break;
  }

  // Delete Order
  case 3: {
    portal();
    cout << "Please insert the ID of the Order you want to delete" << endl;

    cout << endl;
    cout << "0) Cancel operation" << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "Your choice: ";

    int id;
    cin >> id;
    if (id == 0) {
      runAdmin();
    } else {
      orderLinkedList.deleteOrder(id);
      getch();
    }

    break;
  }

  // Generate Report
  case 4: {
    system("cls");
    orderLinkedList.generateReport();

    cout << "\nPress any key to go back to main menu...";
    getch();
    break;
  }

  // Exit
  case 0: {
    system("cls");
    cout << "Exiting application. Press any key to continue....";
    getch();
    system("cls");
    exit(0);
    break;
  }
  default: {
    system("cls");
    cout << "\n--------------------------------------------" << endl;
    cout << "Please enter valid input. Press any key to proceed further...";
    getch();
    break;
  }
  }
}

#endif