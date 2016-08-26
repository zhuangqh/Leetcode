class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int prev = 0;
        int ans = size + 1;
        
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i - prev + 1);
                sum -= nums[prev++];
            }
        }
        
        return ans == size + 1 ? 0 : ans;
    }
};