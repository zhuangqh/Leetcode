// create on 2016-01-11

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    // the longest subsequence's length which end with len[i]
    vector<int> len(nums.size());
    int max = 0;

    for (int i = 0; i < nums.size(); ++i) {
      len[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i] && len[j] + 1 > len[i])
          len[i] = len[j] + 1;
      }
      if (len[i] > max) max = len[i];
    }

    return max;
  }
};
