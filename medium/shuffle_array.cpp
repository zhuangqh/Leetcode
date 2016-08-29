class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        this->shuf = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = nums.size();
        
        while (size) {
            int ran = rand() % size;
            swap(shuf[ran], shuf[--size]);
        }
        return shuf;
    }
    
private:
    vector<int> nums;
    vector<int> shuf;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 