#include <vector>
#include <algorithm>
class Solution {
public:
  int removeElement(std::vector<int>& nums, int val) {
    return remove(nums.begin(), nums.end(), val) - nums.begin();
  }
};
