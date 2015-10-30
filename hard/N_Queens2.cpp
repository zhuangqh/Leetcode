/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-30 19:11:00
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void RNQueens(int& ans, int cur, int n, vector<bool>& col,
                vector<bool>& diag, vector<bool>& antidiag) {
    if (cur == n) {
      ++ans;
      return;
    }

    for (unsigned i = 0; i < n; ++i) {
      // check if the position is valid
      if (col[i] || diag[cur + i] || antidiag[cur + n - 1 - i])
        continue;

      // update info
      col[i] = true;
      diag[cur + i] = true;
      antidiag[cur + n - 1 - i] = true;

      RNQueens(ans, cur + 1, n, col, diag, antidiag);

      col[i] = false;
      diag[cur + i] = false;
      antidiag[cur + n - 1 - i] = false;
    }
  }
  int totalNQueens(int n) {
    int ans = 0;
    vector<bool> colUsed(n, false),
      diag(2*n - 1, false),
      antidiag(2*n - 1, false);
    RNQueens(ans, 0, n, colUsed, diag, antidiag);

    return ans;
  }
};
