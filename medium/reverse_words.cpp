#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
  void reverseWords(string &s) {
    if (s.empty()) return ;

    string ans;
    int pre, post;
    bool flag = true;
    pre = post = s.size() - 1;

    for (int i = s.size() - 1; i >= 0; --i) {
      if (i == 0) {
        if (s[0] != ' ') {
          if (flag) flag = false;
          else ans += " ";
          ans += s.substr(0, post + 1);
        }
        break;
      }

      if (s[i] == ' ' && s[i-1] != ' ') {
        post = i - 1;
      } else if (s[i] != ' ' && s[i-1] == ' ') {
        pre = i;
        if (flag) flag = false;
        else ans += " ";
        ans += s.substr(pre, post - pre + 1);
      }
    }

    s = ans;
  }
};

int main() {
  Solution a;
  string test("a ");
  a.reverseWords(test);
  std::cout << test << std::endl;
  return 0;
}
