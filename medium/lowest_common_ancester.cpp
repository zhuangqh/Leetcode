// create on 2016-01-09 20:53

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // return when one of them is found
    if (!root || root == p || root == q) return root;

    // a node include p, q or both in the left sub-tree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
  }
};
