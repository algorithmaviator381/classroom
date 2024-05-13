#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct InventoryItem
{
    int productId;
    string productName;
    double unitPrice;
    int quantityInHand;
    int quantitySold;
    double inventoryValue;
    double revenue;
};

vector<InventoryItem> inventoryData;

void loadInventoryData()
{
    ifstream inputFile("inventory.csv");

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    inventoryData.clear(); // Clear existing data

    string line;
    getline(inputFile, line); // Skip the header line

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        InventoryItem item;
        ss >> item.productId;
        ss.ignore(); // Ignore the tab
        getline(ss, item.productName, '\t');
        ss >> item.unitPrice;
        ss.ignore(); // Ignore the tab
        ss >> item.quantityInHand;
        ss.ignore(); // Ignore the tab
        ss >> item.quantitySold;
        ss.ignore(); // Ignore the tab
        ss >> item.inventoryValue;
        ss.ignore(); // Ignore the tab
        ss >> item.revenue;

        inventoryData.push_back(item);
    }

    inputFile.close();
}

void saveInventoryData()
{
    ofstream outputFile("inventory.csv");

    if (!outputFile.is_open())
    {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    // Write header
    outputFile << "product_id\tproduct_name\tunit_price\tQuantity_in_hand\tQuantity_sold\tInventory_value\trevenue\n";

    for (const auto &item : inventoryData)
    {
        outputFile << item.productId << "\t"
                   << item.productName << "\t"
                   << item.unitPrice << "\t"
                   << item.quantityInHand << "\t"
                   << item.quantitySold << "\t"
                   << item.inventoryValue << "\t"
                   << item.revenue << "\n";
    }

    outputFile.close();
}

void modifyInventoryItem(int id)
{
    if (id < 1 || id > inventoryData.size())
    {
        cout << "Invalid ID." << endl;
        return;
    }

    cout << "Modify product name: ";
    cin.ignore(); // Clear newline from buffer
    getline(cin, inventoryData[id - 1].productName);

    cout << "Modify unit price: ";
    cin >> inventoryData[id - 1].unitPrice;

    cout << "Modify quantity in hand: ";
    cin >> inventoryData[id - 1].quantityInHand;

    cout << "Modify quantity sold: ";
    cin >> inventoryData[id - 1].quantitySold;

    cout << "Modify inventory value: ";
    cin >> inventoryData[id - 1].inventoryValue;

    cout << "Modify revenue: ";
    cin >> inventoryData[id - 1].revenue;
}

void displayInventory()
{
    cout << "product_id\tproduct_name\tunit_price\tQuantity_in_hand\tQuantity_sold\tInventory_value\trevenue\n";
    for (const auto &item : inventoryData)
    {
        cout << item.productId << "\t"
             << item.productName << "\t"
             << item.unitPrice << "\t"
             << item.quantityInHand << "\t"
             << item.quantitySold << "\t"
             << item.inventoryValue << "\t"
             << item.revenue << "\n";
    }
}

int main()
{
    loadInventoryData();

    int choice;
    do
    {
        cout << "1. Display Inventory\n";
        cout << "2. Modify Inventory Item\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayInventory();
            break;
        case 2:
        {
            int itemId;
            cout << "Enter the product ID of the item to modify: ";
            cin >> itemId;
            modifyInventoryItem(itemId);
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    saveInventoryData();

    return 0;
}
