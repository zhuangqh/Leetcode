class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, index = m + n - 1;
        while (index >= 0) {
            if (p2 < 0) return;

            int value1 = p1 < 0 ? -22222222 : nums1[p1],
                value2 = nums2[p2];
            if (value1 >= value2) {
                nums1[index--] = nums1[p1--];
            } else {
                nums1[index--] = nums2[p2--];
            }
        }
    }
};
