#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution {
public:
  int minimumTotal(vector<vector<int> >& triangle) {
    if (triangle.empty() || triangle[0].empty())
      return 0;

    vector<int> buf(triangle[triangle.size() - 1]);

    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        buf[j] = min(buf[j], buf[j+1]) + triangle[i][j];
      }
    }

    return buf[0];
  }
};
