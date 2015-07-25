#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    if (root == NULL)
      return 0;

    if (!root->left && !root->right)
      return root->val;

    int sum = 0;
    if (root->left)
      sum += root->val * 10 + sumNumbers(root->left);
    if (root->right)
      sum += root->val * 10 + sumNumbers(root->right);

    return sum;
  }
};
