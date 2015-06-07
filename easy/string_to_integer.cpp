#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
class Solution {
public:
  int myAtoi(std::string str) {
    std::stringstream ss;
    int pre, post;
    long long num;
    pre = post = 0;
    bool flag = true;
    for (int i = 0; i < str.size(); ++i) {

      if (flag) {
        if (isdigit(str[i]) || str[i] == '-') {
          pre = i;
          flag = false;
        } else if (str[i] == '+') {

          if (str[i+1] == '-') {
            return 0;
          } else {
            pre = i;
            flag = false;
          }

        } else if (isalpha(str[i])) {
          return 0;
        }
      } else {
        if (!isdigit(str[i]) && str[i] != '.') {
          post = i;
          break;
        }
      }

    }

    if (flag) return 0;
    if (post == 0) post = str.size();
    ss << str.substr(pre, post - pre);
    ss >> num;
    if (num > 2147483647)
      return 2147483647;
    if (num < -2147483648)
      return -2147483648;
    return num;
  }
};

int main() {
  Solution a;
  std::string input;
  std::cin >> input;
  std::cout << a.myAtoi(input) << std::endl;
  return 0;
}
