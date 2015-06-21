#include <iostream>
#include <vector>
class Solution {
public:
  int singleNumber(std::vector<int>& nums) {
    int bit_num[32] = {0};
    int ans = 0;
    for (int i = 0 ; i < 32; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if ((nums[j] >> i) & 1)
          ++bit_num[i];
      }
      ans |= ((bit_num[i] % 3) << i);
    }
    return ans;
  }
};
