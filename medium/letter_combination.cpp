#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  void Rlettercomb(vector<string>& ans, vector<string>& inputs, int n,
                   string tmp, int level) {
    if (level == n) {
      ans.push_back(tmp);
      return ;
    }

    for (int i = 0; i < inputs[level].size(); ++i) {
      tmp += inputs[level][i];
      Rlettercomb(ans, inputs, n, tmp, level + 1);
      tmp = tmp.substr(0, tmp.size() - 1);
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return vector<string>();
    string digi2letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno",
                              "pqrs", "tuv", "wxyz"};

    vector<string> inputs;
    for (int i = 0; i < digits.length(); ++i) {
      if (digits[i] == '1') return vector<string>(1, "");
      inputs.push_back(digi2letter[digits[i] - '0']);
    }

    vector<string> ans;
    string tmp;
    Rlettercomb(ans, inputs, inputs.size(), tmp, 0);

    return ans;
  }
};
