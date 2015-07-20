#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL) return true;
    return judge(root->left, root->right);
  }
  bool judge(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {
      return true;
    } else if (left != NULL && right != NULL) {

      if (left->val != right->val) {
        return false;
      } else {
        return judge(left->left, right->right) &&
          judge(left->right, right->left);
      }

    } else {
      return false;
    }
  }
};
