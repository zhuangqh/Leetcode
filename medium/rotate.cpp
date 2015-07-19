#include <iostream>
#include <vector>
#include <algorithm>

using std::swap;
using std::vector;

class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    if (matrix.size() <= 1) {
      return;
    }

    // operate '\'
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i+1; j < matrix.size(); ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // operate '|'
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix.size() / 2; ++j) {
        swap(matrix[i][j], matrix[i][matrix.size()-j-1]);
      }
    }
  }
};
