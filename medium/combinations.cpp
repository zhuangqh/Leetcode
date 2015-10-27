#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int> > ans;
  vector<int> temp;
public:
  vector<vector<int> > combine(int n, int k) {
    Rcombine(1, n, k, temp);
    return ans;
  }

  void Rcombine(int cur, int n, int level, vector<int> &temp) {
    if (level < 0) return;

    if (level == 0) {
      ans.push_back(temp);
      return;
    }

    for (int i = cur; i + level <= n + 1; ++i) {
      temp.push_back(i);
      Rcombine(i+1, n, level-1, temp);
      temp.pop_back();
    }
  }
};
