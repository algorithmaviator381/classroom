#include <iostream>

#include "controller.h"

using namespace std;

void handleAction(int opt) {
  switch (opt) {
  case 1: {
    runAdmin();
    break;
  }
  case 0: {
    cout << "\n--------------------------------------------" << endl;
    cout << "Please try again with valid username and password" << endl;
    break;
  }
  }
}

int main() {
  menu();


  int opt = login(username, password);

  // Insert hardcoded data

  loadData();

  while (true) {
    handleAction(opt);
  }

  cout << "\n--------------------------------------------" << endl;
  cout << "> Thank You..." << endl;

  return 0;
}