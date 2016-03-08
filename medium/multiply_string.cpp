#include <iostream>
#include <string>
#include <vector>
#include "../helper.h"

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    vector<int> ans(num1.size() + num2.size(), 0);
    if (ans.empty()) return "";

    for (int i = num1.size() - 1; i >= 0; --i) {
      int ptr = num1.size() - i - 1;
      for (int j = num2.size() - 1; j >= 0; --j) {
        ans[ptr] += multiply(num1[i], num2[j]);

        ++ptr;
      }
    }

    // carry in
    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i] > 9) {
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
      }
    }

    return vector2string(ans);
  }

  int multiply(char a, char b) {
    return (a - '0') * (b - '0');
  }

  string vector2string(vector<int>& vec) {
    int ptr = vec.size() - 1;
    // find the real length
    while (ptr >= 0 && !vec[ptr]) {--ptr;}
    if (ptr < 0) return "0";
    string ans(ptr + 1, '0');
    for (int i = 0; i < ans.length(); ++i) {
      ans[i] = vec[ans.length() - 1 - i] + '0';
    }

    return ans;
  }
};

int main() {
  Solution a;
  cout << a.multiply("909", "99") << endl;

  return 0;
}
