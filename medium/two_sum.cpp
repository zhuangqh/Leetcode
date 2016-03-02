#include <iostream>
#include <vector>
#include <map>
#include "../helper.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(target - nums[i]) != m.end()) {
        ans.push_back(m[target - nums[i]]);
        ans.push_back(i);
        break;
      }
      m[nums[i]] = i;
    }

    return ans;
  }
};

int main() {
  helper h;
  vector<int> vec = h.vectorGenerator(10);
  Solution a;
  vec = a.twoSum(vec, 7);
  h.printVector(vec);

  return 0;
}
