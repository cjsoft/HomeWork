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

bool checkinput(const string &inpt) {                   //输入合法性检查：不接受前导0，不接受空输入，不接受长度大于4的输入
  if (inpt.length() > 4 || inpt.length() == 0 || (inpt.length() > 1 && inpt[0] == '0')) return false;
  for (unsigned int i = 0; i < inpt.length(); i++) {
    if (!isdigit(inpt[i]))
      return false;
  }
  return true;
}


int main() {
  srand(time(0));                           // 初始化随机数种子
  int realprice, guessprice;
  string userinput;
  realprice = rand() % 1000 + 1;            // 生成随机答案
  guessprice = 0;
  cout << "输入应当不超过4个字符，";
  while (guessprice != realprice) {         // 循环判断
    cout << PROMPT_FOR_INPUT;
    getline(cin, userinput);                // 读入
    if (checkinput(userinput)) {            // 检查合法性
        guessprice = atoi(userinput.c_str()); // 转换
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
