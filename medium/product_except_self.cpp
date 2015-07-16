#include <iostream>
#include <vector>
class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> ans(size, 1);
    std::vector<int> l2r(ans), r2l(ans);
    //  left to right
    l2r[0] = nums[0];
    for (int i = 1; i < size; ++i) {
      l2r[i] = l2r[i-1] * nums[i];
      ans[i] *= l2r[i-1];
    }
    //  right to left
    r2l[size - 1] = nums[size - 1];
    for (int i = size - 2; i >= 0; --i) {
      r2l[i] = r2l[i+1] * nums[i];
      ans[i] *= r2l[i+1];
    }

    return ans;
  }
};
