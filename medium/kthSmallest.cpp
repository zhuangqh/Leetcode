#include "../utils/common.h";

using namespace std;

// val, index i, j
// sort according to val
typedef pair<int, pair<int, int> > item;

struct minor {
  bool operator ()(item &a, item &b){
    return a.first > b.first;//最小值优先
  }
};

class Solution {
public:
  int kthSmallest(vector<vector<int> >& matrix, int k) {
    priority_queue<item, vector<item>, minor> pq;

    for (int i = 0; i < matrix.size(); ++i) {
      pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
    }

    while (--k) {
      auto ptr = pq.top().second;
      pq.pop();

      if (ptr.second + 1 < matrix[ptr.first].size()) {
        const int& i = ptr.first;
        const int& j = ptr.second;
        pq.push(make_pair(matrix[i][j + 1], make_pair(i, j + 1)));
      }
    }

    return pq.top().first;
  }
};
