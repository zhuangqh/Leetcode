class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int m = matrix.size(), n = matrix[0].size();
        
        set<int> row, col;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for (auto it = row.begin(); it != row.end(); ++it) {
            for (int k = 0; k < n; ++k)
                matrix[*it][k] = 0;
        }
        
        for (auto it = col.begin(); it != col.end(); ++it) {
            for (int k = 0; k < m; ++k)
                matrix[k][*it] = 0;
        }
    }
};