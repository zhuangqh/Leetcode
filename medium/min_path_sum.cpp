#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
  int minPathSum(vector<vector<int> >& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int m = grid.size(), n = grid[0].size();
    vector<vector<int> > f = grid;

    f[0][0] = grid[0][0];

    //  initialize
    for (int i = 1; i < m; ++i) {
      f[i][0] = f[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
      f[0][j] = f[0][j-1] + grid[0][j];
    }
    // dp
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
      }
    }

    return f[m-1][n-1];
  }
};

int main() {
  vector<int> v1{1, 2}, v2{1, 1};
  vector<vector<int> > test{v1, v2};
  Solution a;

  std::cout << a.minPathSum(test) << std::endl;
}
