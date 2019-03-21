#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#define PROMPT_FOR_INPUT "请输入你的猜测:"
#define PROMPT_FOR_SUCCESS "您猜对了"
#define PROMPT_INPUT_ILLEGAL "您输入的不合法"
#define PROMPT_ANSWER_IS_GREATER "真正的答案比你猜的大"
#define PROMPT_ANSWER_IS_LESS "真正的答案比你猜的小"
using namespace std;

bool checkinput(string inpt) {
  for (unsigned int i = 0; i < inpt.length(); i++) {
    if (!isdigit(inpt[i]))
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
    cout << PROMPT_FOR_INPUT;
    getline(cin, userinput);
    if (checkinput(userinput)) {
        guessprice = atoi(userinput.c_str());
        if (guessprice < realprice) {
            cout << PROMPT_ANSWER_IS_GREATER << endl;
        } else {
            cout << PROMPT_ANSWER_IS_LESS << endl;
        }
    } else {
        cout << PROMPT_INPUT_ILLEGAL << endl;
    }
  }
  cout << PROMPT_FOR_SUCCESS << endl;
  return 0;
}
