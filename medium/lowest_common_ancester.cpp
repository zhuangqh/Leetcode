// create on 2016-01-09 20:53

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isAncestor(TreeNode* root, TreeNode* node) {
    if (root == NULL) return false;
    return node == root ||
      isAncestor(root->left, node) || isAncestor(root->right, node);
  }
  bool isCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return isAncestor(root, p) && isAncestor(root, q);
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;

    bool left = isCommonAncestor(root->left, p, q),
      right = isCommonAncestor(root->right, p, q);

    if (left && !right) {
      return lowestCommonAncestor(root->left, p, q);
    } else if (!left && right) {
      return lowestCommonAncestor(root->right, p, q);
    } else if (!left && !right) {
      return root;
    } else {
      return NULL;
    }
  }
};
