/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-29 23:53:12
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> temp;
public:
    void RNQueens(vector<string>& temp, int level, int n, vector<bool>& col,
                                vector<bool>& diag, vector<bool>& antidiag) {
        if (level == 0) {
            ans.push_back(temp);
            return;
        }

        for(unsigned i = 0; i < n; ++i) {
            // check if the position is valid
            if (col[i] || diag[temp.size() + i] ||
                antidiag[temp.size() + n - 1 - i])
                continue;

            // update info
            col[i] = true;
            diag[temp.size() + i] = true;
            antidiag[temp.size() + n - 1 - i] = true;

            string line(n, '.');
            line[i] = 'Q';
            temp.push_back(line);
            RNQueens(temp, level - 1, n, col, diag, antidiag);

            col[i] = false;
            diag[temp.size() + i - 1] = false;
            antidiag[temp.size() + n - 2 - i] = false;
            temp.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>    colUsed(n, false),
                        diag(2*n - 1, false),
                        antidiag(2*n - 1, false);
        RNQueens(temp, n, n, colUsed, diag, antidiag);
        // cout << ans.size() << endl;
        return ans;
    }
};

int main() {
    Solution a;
    a.solveNQueens(8);

    return 0;
}