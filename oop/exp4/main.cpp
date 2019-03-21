#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

bool checkinput(string inpt) {
  for (int i = 0; i < inpt; i++) {
    if (!isdigit(inpt))
      return false;
  }
  return true;
}

int main() {
  int realprice, guessprice;
  string userinput;
  realprice = rand() % 1000 + 1;
  guessprice = 0;
  while (guessprice != realprice) {
    cout;
  }
  return 0;
}