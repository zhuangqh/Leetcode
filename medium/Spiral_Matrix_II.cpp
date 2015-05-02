#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    int counter = 1;
    vector<vector<int> > ans;
    for (int i = 0; i < n; ++i) {
      vector<int> temp(n, -1);
      ans.push_back(temp);
    }
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int loop_time = n - 1;
    for (int i = 0; i <= (n - 1) / 2 && counter <= n * n;) {
      int j = i;
      cout << "fuck" << i << " " << j << endl;
      ans[i][j] = counter++;
      for (int go = 0; go < 4; ++go) {
        for (int k = 0; k < loop_time && counter <= n * n; ++k) {
          if (go == 3 && k == loop_time - 1) {
            break;
          } else {
            i += dir[go][0];
            j += dir[go][1];
            ans[i][j] = counter++;
          }
        }
      }
      loop_time -= 2;
    }
    return ans;
  }
};
