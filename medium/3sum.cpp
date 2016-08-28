class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum == 0) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j < nums.size() - 1 && nums[j + 1] == nums[j]) ++j;
                    while (k > 0 && nums[k - 1] == nums[k]) --k;
                    
                    ++j;
                    --k;
                } else if (sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        
        return ans;
    }
};
