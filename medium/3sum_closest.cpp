class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        int minDist = INT_MAX;
        int ans = 0;
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int tmp = nums[j] + nums[k] + nums[i];
                int dist = abs(tmp - target);
                if (dist < minDist) {
                    minDist = dist;
                    ans = tmp;
                }
                
                (tmp > target) ? --k : ++j;
            }
        }
        
        return ans;
    }
};
