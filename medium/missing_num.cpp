class Solution {
public:
  int missingNumber(vector<int>& nums) {
    if (nums.empty()) return 0;
    int sum = 0, n = nums.size();
    for (auto jj : nums) {
      sum += jj;
    }

    return (n*(n+1)/2 - sum);
  }
};
