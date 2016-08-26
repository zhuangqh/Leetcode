class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = nums1.size() - 1; i >= 0; --i) {
            if (nums1[i] == nums1[i + 1]) continue;
            if (binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                ans.push_back(nums1[i]);
            }
        }
        return ans;
    }
};
