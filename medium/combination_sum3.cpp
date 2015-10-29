/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-29 23:16:03
 */

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void RcombSum(vector<int>& temp, int level, int cur, int target) {
        if (level < 0) return;

        if (target == 0 && level == 0) {
            ans.push_back(temp);
            return;
        }

        for(unsigned i = cur; i <= 9 && target >= i; ++i) {
            temp.push_back(i);
            RcombSum(temp, level-1, i+1, target - i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        RcombSum(temp, k, 1, n);
        return ans;
    }
};