// create on 2016-01-12

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int> > &matrix) {
    if (matrix.empty()) return;

    int row = matrix.size(),
      col = matrix[0].size();
    regionSum.assign(row+1, vector<int>(col+1, 0));

    // accumlated sum
    for (int i = 1; i <= row; ++i) {
      for (int j = 1; j <= col; ++j) {
        regionSum[i][j] = regionSum[i][j-1]
          + regionSum[i-1][j] - regionSum[i-1][j-1] + matrix[i-1][j-1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    // check if valid
    if (row1 < 0 ||
        row2 >= regionSum.size() || col1 < 0 || col2 >= regionSum[0].size())
      return 0;

    return regionSum[row2+1][col2+1] - regionSum[row2+1][col1]
                      - regionSum[row1][col2+1] + regionSum[row1][col1];
  }
private:
  vector<vector<int> > regionSum;
};
