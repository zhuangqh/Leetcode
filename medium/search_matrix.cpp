#include <vector>

using std::vector;

class Solution {
public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size(), n = matrix[0].size(),
      l = 0, r = m * n - 1;

    while (l < r) {
      int mid = (l + r) / 2;

      if (matrix[mid / n][mid % n] == target) {
        return true;
      } else if (matrix[mid / n][mid % n] > target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    if (matrix[l / n][l % n] == target) return true;
    else return false;
  }
};
