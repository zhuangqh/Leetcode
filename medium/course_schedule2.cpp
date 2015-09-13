#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::pair;
using std::queue;

class Solution {
public:
  vector<int> findOrder(int n, vector<pair<int, int> >& prereq) {
    vector<vector<bool> > graph(n, vector<bool>(n, false));
    vector<int> indegree(n, 0);
    vector<int> order;

    for (auto it = prereq.begin(); it != prereq.end(); ++it) {
      if (graph[it->second][it->first] == false) {
        graph[it->second][it->first] = true;
        ++indegree[it->first];
      }
    }

    queue<int> buf;
    int count = 0;

    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) {
        buf.push(i);
      }
    }

    while (!buf.empty()) {
      int now = buf.front();
      buf.pop();
      order.push_back(now);

      ++count;

      for (int i = 0; i < n; ++i) {
        if (graph[now][i]) {

          if (--indegree[i] == 0)
            buf.push(i);

        }
      }
    }

    if (count == n)
      return order;
    else
      return vector<int>();
  }
};
