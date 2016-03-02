#include <iostream>
#include <vector>
#include "../helper.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    bool found = false;
    for (int i = 0; i < nums.size() - 1 && !found; ++i) {
      ans.assign(1, i);
      for (int j = i + 1; j < nums.size() && !found; ++j) {
        if (nums[i] + nums[j] == target) {
          ans.push_back(j);
          found = true;
        }
      }
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
