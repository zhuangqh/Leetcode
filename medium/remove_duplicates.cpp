class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int p = 0;
        bool hasDup = false;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (hasDup && nums[i] == nums[p]) continue;
            
            if (nums[i] != nums[p]) {
                hasDup = false;
            } else {
                hasDup = true;
            }
            
            nums[++p] = nums[i];
        }
        
        return p + 1;
    }
};