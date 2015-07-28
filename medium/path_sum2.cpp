#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    if (root)
      dfs(root, sum);
    return ans;
  }

private:
  vector<vector<int> > ans;
  vector<int> curPath;
  void dfs(TreeNode *root, int sum) {
    sum -= root->val;

    curPath.push_back(root->val);
    if (!root->left && !root->right && sum == 0)
      ans.push_back(curPath);
    if (root->left)
      dfs(root->left, sum);
    if (root->right)
      dfs(root->right, sum);

    curPath.pop_back();
  }
};
