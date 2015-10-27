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
    return Rcheck(root);
  }

  bool Rcheck(TreeNode* root) {
    if (root == NULL) return true;

    bool ans = true;

    if (root->left && (root->left->val > root->val) ) {
      ans = false;
    }

    if (root->right && root->right->val < root->val) {
      ans = false;
    }

    return ans && Rcheck(root->left) && Rcheck(root->right);
  }
};
