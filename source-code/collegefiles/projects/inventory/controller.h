#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <conio.h>
#include <iostream>
#include <string>

#include "login.h"
#include "purchaseOrder.h"

using namespace std;

string username, password;
string mode[] = {"product", "price", "Quantity", "customerName"};
string status[] = {"Processing", "Released", "Received", "Canceled"};

void menu()
{
  system("cls");
  cout << "-----Purchase Order Management System-----" << endl;
  cout << "Please enter Username and Password to login." << endl;
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;
  cout << endl;
}

void loadData()
{
  orderLinkedList.insertAtEnd("Low-fat milk", 30.0, 1, "Summerhill");
  orderLinkedList.insertAtEnd("Alphonso", 200.0, 4, "Summerhill");
  orderLinkedList.insertAtEnd("Apples", 80.0, 4, "Summerhill");
  orderLinkedList.insertAtEnd("Watermelon", 120.0, 4, "Summerhill");
  orderLinkedList.insertAtEnd("ButterScotch", 50.0, 1, "Summerhill");
  orderLinkedList.insertAtEnd("Badaam Kulfi", 150.0, 3, "Summerhill");
  orderLinkedList.insertAtEnd("Wispher", 10.0, 10, "Summerhill");
  orderLinkedList.insertAtEnd("Badaam", 350.0, 5, "Summerhill");
  orderLinkedList.insertAtEnd("Ink Pen", 20.0, 10, "Summerhill");
  orderLinkedList.insertAtEnd("Sketchpen", 18.0, 10, "Summerhill");
  orderLinkedList.insertAtEnd("Notebooks", 40.0, 10, "Summerhill");
  orderLinkedList.insertAtEnd("Pop Corn", 80.0, 2, "Summerhill");
  orderLinkedList.insertAtEnd("Umbrella", 300.0, 1, "Summerhill");
  orderLinkedList.insertAtEnd("Hercules", 1200.0, 2, "Summerhill");
  orderLinkedList.insertAtEnd("Raisins", 450.0, 2, "Summerhill");
  orderLinkedList.insertAtEnd("Cashew", 600.0, 3, "Summerhill");
}

void portal()
{
  system("cls");
  cout << endl;
  cout << "----------------------------------------------------------------"
       << endl;
  cout << "Welcome to R2PO CLI procurement application portal " << globalName
       << endl;
  cout << "----------------------------------------------------------------"
       << endl;
  cout << "\nPurchase Order summary: " << endl
       << endl;

  orderLinkedList.display();
  cout << "-------------------------------------------------" << endl;
  cout << endl;
}

void runAdmin()
{
  portal();

  orderLinkedList.results = 0;
  int opt;

  cout << "1) Modify Order details" << endl;
  cout << "2) Search Order" << endl;
  cout << "3) Delete Order" << endl;
  cout << "4) Generate Report" << endl;
  cout << "5) Add Item" << endl;
  cout << "6) Generate PO (.txt file)" << endl;

  cout << endl;
  cout << "0) Exit" << endl;

  cout << "-------------------------------------------------" << endl;
  cout << "> Choose: ";
  cin >> opt;

  switch (opt)
  {

  // Modify Order
  case 1:
  {
    portal();
    cout << "Please insert the ID of the Order to be modified." << endl;

    cout << endl;
    cout << "0) Back" << endl;

    cout << "-------------------------------------------------" << endl;
    cout << "> Input: ";
    int id;
    cin >> id;

    if (id == 0)
    {
      runAdmin();
    }
    else
    {
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

      switch (opt)
      {
      case 1:
      {
        string productName;
        orderLinkedList.modifyMode = "productName";

        cout << "Please insert new Product Name: " << endl;
        cin.ignore();
        getline(cin, productName);
        // cin>>productName;

        orderLinkedList.modifyOrder(id, productName);
        break;
      }
      case 2:
      {
        orderLinkedList.modifyMode = "price";
        cout << "Please insert new Price: " << endl;
        double price;
        cin >> price;

        if (price > 0)
        {
          orderLinkedList.modifyOrderPrice(id, price);
        }
        else
        {
          cout << "Invalid Price!";
        }

        break;
      }
      case 3:
      {
        cout << "Please insert the updated quantity of product:" << endl;
        int quantity;
        cin >> quantity;

        orderLinkedList.modifyOrderQuantity(id, quantity);

        break;
      }
      case 4:
      {
        orderLinkedList.modifyMode = "customerName";
        cout << "Please insert new customer Name:" << endl;
        string customerName;
        cin.ignore();
        getline(cin, customerName);

        orderLinkedList.modifyOrder(id, customerName);

        break;
      }
      case 0:
      {
        runAdmin();
        break;
      }
      default:
      {
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
  case 2:
  {
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

    switch (opt)
    {
    case 1:
    {
      cout << "Please insert ID to search:" << endl;
      int id;
      cin >> id;

      orderLinkedList.searchOrderById(id);
      getch();
      break;
    }
    case 2:
    {
      cout << "Please insert Product Name to search:" << endl;
      string productName;
      cin >> productName;

      orderLinkedList.searchOrderByProductName(productName);
      getch();
      break;
    }
    case 3:
    {
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
    case 4:
    {
      cout << "Please insert Customer Name to search:" << endl;
      string customerName;
      cin >> customerName;

      orderLinkedList.searchOrderByCustomerName(customerName);
      getch();
      break;
    }
    case 0:
    {
      runAdmin();
      break;
    }
    default:
    {
      cout << "\n--------------------------------------------" << endl;
      cout << "> Thank You..." << endl;
      exit(0);
      break;
    }
    }
    break;
  }

  // Delete Order
  case 3:
  {
    portal();
    cout << "Please insert the ID of the Order you want to delete" << endl;

    cout << endl;
    cout << "0) Cancel operation" << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "Your choice: ";

    int id;
    cin >> id;
    if (id == 0)
    {
      runAdmin();
    }
    else
    {
      orderLinkedList.deleteOrder(id);
      getch();
    }

    break;
  }

  // Generate Report
  case 4:
  {
    system("cls");
    orderLinkedList.generateReport();

    cout << "\nPress any key to go back to main menu...";
    getch();
    break;
  }

  case 5:
  {
    system("cls");

    cout << "Add New Item" << endl;
    cout << "-------------------------------------------------" << endl;

    string productName;
    double price;
    int quantity;
    string customerName;

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, productName);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    orderLinkedList.insertAtEnd(productName, price, quantity, customerName);

    cout << "\nItem added successfully!" << endl;
    cout << "Press any key to go back to the main menu...";
    getch();
    break;
  }

    // Generate po
  case 6:
  {
    orderLinkedList.generatePurchaseOrder();

    system("cls");
    cout << "\nPurchase order information saved in text file named PurchaseOrder.txt\n";
    cout << "\nPress any key to go back to main menu...";
    getch();
    break;
  }

  // Exit
  case 0:
  {
    system("cls");
    cout << "Exiting application. Press any key to continue....";
    getch();
    system("cls");
    exit(0);
    break;
  }
  default:
  {
    system("cls");
    cout << "\n--------------------------------------------" << endl;
    cout << "Please enter valid input. Press any key to proceed further...";
    getch();
    break;
  }
  }
}

#endif