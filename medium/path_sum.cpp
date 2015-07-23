#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL)
      return false;

    return (root->val == sum && !root->left && !root->right)
      || hasPathSum(root->left, sum - root->val)
      || hasPathSum(root->right, sum - root->val);
      }
};
