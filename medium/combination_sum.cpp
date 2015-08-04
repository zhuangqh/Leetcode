#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution {
public:
  vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    combinationSum(candidates, target, 0);
    return res;
  }
private:
  vector<vector<int> > res;
  vector<int> combination;
  void combinationSum(vector<int>& candidates, int target, int begin) {
    if (target == 0) {
      res.push_back(combination);
      return;
    }

    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
      combination.push_back(candidates[i]);
      combinationSum(candidates, target - candidates[i], i);
      combination.pop_back();
    }
  }
};
