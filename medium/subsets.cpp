/*
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-28 20:34:25
 */

class Solution {
private:
  vector<vector<int> > ans;
  vector<int> temp;
public:
  void Rsubsets(int i, vector<int>& nums) {
    if (i == nums.size()) {
      ans.push_back(temp);
      return;
    }

    temp.push_back(nums[i]);
    Rsubsets(i+1, nums);
    temp.pop_back();
    Rsubsets(i+1, nums);
  }
  vector<vector<int> > subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    Rsubsets(0, nums);
    return ans;
  }
};