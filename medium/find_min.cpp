#include <vector>
class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int size = nums.size() - 1;
        int l = 0, r = size;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[size]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }
};
