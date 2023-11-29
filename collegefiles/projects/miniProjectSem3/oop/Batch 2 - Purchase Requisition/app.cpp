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
  default:
    break;
  }
}

int main() {
  menu();

  //Username: adimail
  //Password: sonchafa
  
  int opt = login(username, password);

  loadData();

  while (true) {
    handleAction(opt);
  }

  cout << "\n--------------------------------------------" << endl;
  cout << "> Thank You..." << endl;

  return 0;
}