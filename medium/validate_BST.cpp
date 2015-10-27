#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return Rcheck(root, NULL, NULL);
  }

  bool Rcheck(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (root == NULL) return true;

    if (minNode && root->val <= minNode->val
      || maxNode && root->val >= maxNode->val)
      return false;

    return Rcheck(root->left, minNode, root) && Rcheck(root->right, root, maxNode);
  }
};
