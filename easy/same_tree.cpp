//Definition for a binary tree node.
#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
      return true;
    if (p != NULL && q != NULL)
      if (p->val == q->val)
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
          return true;
    return false;
  }
};