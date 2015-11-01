#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    if (nums.empty()) return;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        int ptr = i + 1;
        while (ptr < nums.size() && nums[ptr] == 0) {
          ++ptr;
        }

        if (ptr < nums.size())
          swap(nums[i], nums[ptr]);
      }
    }
  }
};
