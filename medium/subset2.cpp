#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  void Rsubset(const vector<int>& nums, vector<vector<int> >& ans,
               vector<int>& temp, int cur) {
    if (cur <= nums.size()) {
      ans.push_back(temp);
    }

    for (int i = cur; i < nums.size(); ++i) {
      temp.push_back(nums[i]);
      Rsubset(nums, ans, temp, i+1);
      temp.pop_back();
      while (i+1 < nums.size() && nums[i] == nums[i+1]) {
        ++i;
      }
    }
  }
  vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> temp;

    sort(nums.begin(), nums.end());
    Rsubset(nums, ans, temp, 0);
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> ans;

  Solution a;
  ans = a.subsetsWithDup(nums);

  for (auto item: ans) {
    for (auto x: item) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}
