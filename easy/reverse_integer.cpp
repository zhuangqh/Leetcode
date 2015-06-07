#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
class Solution {
public:
  int reverse(int x) {
    long long xx = x;
    bool is_nagetive = false;
    if (xx < 0) {
      xx *= -1;
      is_nagetive = true;
    }
    std::stringstream ss;
    ss << xx;
    std::string output;
    ss >> output;
    ss.clear();
    std::reverse(output.begin(), output.end());
    ss << output;
    ss >> xx;
    if (xx > 2147483647) return 0;
    if (is_nagetive) xx *= -1;
    return xx;
  }
};

int main() {
  int test;
  std::cin >> test;
  Solution a;
  std::cout << a.reverse(test) << std::endl;
  return 0;
}
