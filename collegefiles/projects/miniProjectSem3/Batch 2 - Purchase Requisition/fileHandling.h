#include <fstream>

using namespace std;

#include "purchaseOrder.h"
#include "oc.h"
#include "controller.h"

struct Node
{
public:
  Order order;
  Node *next;
};

class orderll {

public:
  Node *head, *tail;
  int size;
  int results = 0;
  string modifyMode;

  int getSize() { return size; }

  int getTotalPrise() {
    int result = 0;

    Node *curr = head;
    while (curr != nullptr) {
      result += curr->order.price * curr->order.quantity;
      curr = curr->next;
    }

    return result;
  }

  void generatePurchaseOrder() {
    ofstream fout("PurchaseOrder.txt");

    time_t currentTime = time(0);
    char *dt = ctime(&currentTime);

    fout << "Order Date and Time: " << dt << "\n\n";

    fout << "ID       Product Name    Price   Quantity        Customer Name\n";
    fout << "``````````````````````````````````````````````````````````````````"
            "\n";

    Node *curr = this->head;
    while (curr != nullptr) {
      fout << curr->order.id << " \t " << curr->order.productName << " \t  "
           << curr->order.price << "\t " << curr->order.quantity << "\t\t "
           << curr->order.customerName << "\t" << endl;

      curr = curr->next;
    }

    fout << "\nTotal Items: " << this->getSize() << "\n";
    fout << "Total Price: " << this->getTotalPrise() << " rupees\n";

    fout.close();

    cout << "Purchase order details have been saved to 'PurchaseOrder.txt'."
         << endl;
  }
};
