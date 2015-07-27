#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    int len = strs[0].size();

    while (len > 0) {
      int tmp = len;

      for (int i = 1; i < strs.size(); ++i) {
        for (int j = 0; j < len; ++j) {
          if (strs[i][j] != strs[0][j]) {
            tmp = j;
            break;
          }
        }
      }

      if (tmp == len) {
        return strs[0].substr(0, len);
      } else {
        len = tmp;
      }
    }

    return "";
  }
};

int main() {
  Solution a;
  vector<string> test{"aa", "ab"};

  std::cout << a.longestCommonPrefix(test) << std::endl;
}
