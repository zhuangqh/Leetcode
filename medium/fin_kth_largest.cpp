#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

int main() {
  vector<int> test{3, 2, 1, 5, 6, 4};
  Solution a;
  std::cout << a.findKthLargest(test, 2) << std::endl;
  return 0;
}
