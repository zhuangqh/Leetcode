class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if (o.empty() || o[0].empty()) return 0;

        int m = o.size(), n = o[0].size();
        vector<vector<int> > graph(m, vector<int>(n, 1));

        for (int i = 0; i < m; ++i) {
            if (o[i][0]) graph[i][0] = 0;
            if (i && graph[i-1][0] == 0) graph[i][0] = 0;
        }

        for (int j = 0; j < n; ++j) {
            if (o[0][j]) graph[0][j] = 0;
            if (j && graph[0][j-1] == 0) graph[0][j] = 0;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (o[i][j]) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = graph[i-1][j] + graph[i][j-1];
                }
            }
        }

        return graph[m-1][n-1];
    }
};
