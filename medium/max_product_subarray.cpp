#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int maxSum = nums[0], thisSum = 1;
    for (int i = 0; i < nums.size(); ++i) {
      thisSum *= nums[i];

      if (nums[i] > maxSum)
        maxSum = thisSum;
      if (thisSum > maxSum)
        maxSum = thisSum;
      else if (thisSum < 0)
        thisSum = 0;
    }

    return maxSum;
  }
};

int main() {
  vector<int> test{2, 3, -2, 4};
  Solution a;
  std::cout << a.maxProduct(test) << std::endl;
  return 0;
}
