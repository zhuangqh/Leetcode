#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
  vector<string> ans;
public:
  vector<string> generateParenthesis(int n) {
    gphelper(string("("), 1, 0, n);
    return ans;
  }

  void gphelper(string temp, int lp, int rl, int n) {
    if (lp > n || rl > n || rl > lp) return;

    if (lp == n && rl == n) {
      ans.push_back(temp);
    } else if (lp == n && rl < n) {
      temp += ")";
      gphelper(temp, lp, rl + 1, n);
    } else {

      // left parethes
      temp += "(";
      gphelper(temp, lp + 1, rl, n);
      temp = temp.substr(0, temp.size() - 1);

      // right parethes
      temp += ")";
      gphelper(temp, lp, rl +1, n);
      temp = temp.substr(0, temp.size() - 1);
    }
  }
};
