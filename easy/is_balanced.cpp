#include <iostream>
#include <cmath>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == NULL)
      return true;
    if (std::abs(getHeight(root->left) - getHeight(root->right)) > 1)
      return false;

    return isBalanced(root->left) && isBalanced(root->right);
  }
  int getHeight(TreeNode *root) {
    if (root == NULL)
      return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
  }
};
