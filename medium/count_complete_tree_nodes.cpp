#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int getDepth(TreeNode *root) {
    int depth = 0;
    while (root) {
      root = root->left;
      ++depth;
    }
    return depth;
  }
  int countNodes(TreeNode *root) {
    if (root == NULL)
      return 0;
    int lDepth = getDepth(root->left);
    int rDepth = getDepth(root->right);

    if (lDepth == rDepth)
      return (1<<lDepth) + countNodes(root->right);
    else
      return (1<<rDepth) + countNodes(root->left);
  }
};
