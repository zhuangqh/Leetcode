#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int sum;
public:
  int sumNumbers(TreeNode* root) {
    sum = 0;
    RsumNumbers(root, 0);
    return sum;
  }

  void RsumNumbers(TreeNode* root, int total) {
    if (root == NULL) return;

    int curtotal = total*10 + root->val;

    if (!(root->left) && !(root->right)) {
      sum += curtotal;
    }

    if (root->left)
      RsumNumbers(root->left, curtotal);
    if (root->right)
      RsumNumbers(root->right, curtotal);
  }
};
