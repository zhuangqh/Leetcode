#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }

    priority_queue<pair<int, int> > pq;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
      pq.push(make_pair(it->second, it->first));
    }

    vector<int> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }
};
