#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::pair;
using std::queue;

class Solution {
public:
  bool canFinish(int n, vector<pair<int, int> >& prereq) {
    vector<vector<bool> > graph(n, vector<bool>(n, false));
    vector<int> indegree(n, 0);

    for (auto it = prereq.begin(); it != prereq.end(); ++it) {
      graph[it->second][it->first] = true;
      ++indegree[it->first];
    }

    queue<int> buf;
    int count = 0;

    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0)
        buf.push(i);
    }

    while (!buf.empty()) {
      int now = buf.front();
      buf.pop();

      ++count;

      for (int i = 0; i < n; ++i) {
        if (graph[now][i]) {
          if (--indegree[i] == 0) {
            buf.push(i);
          }
        }
      }
    }

    return (count == n);
  }
};
