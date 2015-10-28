/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-29 00:16:44
 */

class Solution {
private:
  vector<vector<int>> ans;
public:
  void Rpermute(vector<int>& nums, int cur, int m) {
    if (cur == m - 1) {
      ans.push_back(nums);
      return;
    }

    for (int i = cur; i < m; ++i) {
      swap(nums[i], nums[cur]);
      Rpermute(nums, cur+1, m);
      swap(nums[i], nums[cur]);
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    Rpermute(nums, 0, nums.size());
    return ans;
  }
};