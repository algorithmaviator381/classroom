#include <iostream>
#include <cstdlib>

#include "controller.h"

using namespace std;

int main()
{
  menu();

  // Username: adimail
  // Password: sonchafa

  int opt = login(username, password);

  loadData();

  while (true)
  {
    runAdmin();
  }

  cout << "\n--------------------------------------------" << endl;
  cout << "> Thank You..." << endl;

  return 0;
}
