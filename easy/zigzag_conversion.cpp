#include <vector>
#include <iostream>
#include <string>
class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1)
      return s;

    std::string ans = s;
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
      int j = i;
      bool flag = true;
      while (j < s.size()) {
        ans[index++] = s[j];
        if (i == 0 || i == numRows - 1) {
          j += 2 * (numRows - 1);
        } else if (flag) {
          j += 2 * (numRows - i - 1);
          flag = false;
        } else {
          j += 2 * i;
          flag = true;
        }
      }
    }
    return ans;
  }
};

int main() {
  std::string test;
  Solution a;
  test = a.convert("PAYPALISHIRING", 3);
  std::cout << test << std::endl;
  return 0;
}
