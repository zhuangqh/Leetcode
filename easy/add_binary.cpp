#include <iostream>
#include <string>
#include <algorithm>

using std::reverse;
using std::string;

class Solution {
public:
  string addBinary(string a, string b) {
    int pa = a.size() - 1, pb = b.size() - 1, plus = 0;
    string ans;
    while (pa >= 0 || pb >= 0) {
      int va = pa >= 0 ? a[pa--] - '0' : 0,
        vb = pb >= 0 ? b[pb--] - '0' : 0;
      ans += (va + vb + plus) % 2 + '0';
      plus = (va + vb + plus) / 2;
    }
    if (plus) ans += '1';
    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main() {
  Solution a;
  string tmp = a.addBinary("11", "1");
  std::cout << tmp << std::endl;
}
