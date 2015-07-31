#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    if (root == NULL) return 0;
    int lnum = countNodes(root->left);

    if (k == lnum + 1) {
      return root->val;
    } else if (k > lnum + 1) {
      return kthSmallest(root->right, k - lnum - 1);
    } else {
      return kthSmallest(root->left, k);
    }
  }
private:
  int countNodes(TreeNode *root) {
    if (root == NULL)
      return 0;
    else
      return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
