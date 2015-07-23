#include <vector>

using std::vector;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int index = 0, colors[3] = {0};
    for (int i = 0; i < nums.size(); ++i) {
      ++colors[nums[i]];
    }

    for (int i = 0; i < nums.size(); ++i) {
      while (colors[index] <= 0) ++index;
      nums[i] = index;
      --colors[index];
    }
  }
};
