/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-29 13:35:40
 */

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
public:
    void findComb(const vector<int>& candidates, int cur, int target,
                                        vector<int>& temp) {
        if (target < 0) return;

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // 小剪枝
        for (int i = cur; i < candidates.size() && target >= candidates[i]; ++i) {
            temp.push_back(candidates[i]);
            findComb(candidates, i+1, target - candidates[i], temp);
            temp.pop_back();
            while (candidates[i] == candidates[i+1]) ++i;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>&
        candidates, int target) {
        sort(candidates.begin(), candidates.end());

        findComb(candidates, 0, target, temp);
        return ans;
    }
};

