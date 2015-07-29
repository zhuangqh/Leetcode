#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == NULL)
      return;

    TreeNode *cur = root;

    preOrder(root);

    for (int i = 0; i < buf.size(); ++i) {
      buf[i]->left = NULL;
      if (i)
        cur->right = buf[i];
      cur = buf[i];
    }
    cur->right = NULL;
  }
private:
  vector<TreeNode*> buf;
  void preOrder(TreeNode *root) {
    if (root == NULL)
      return;

    buf.push_back(root);
    preOrder(root->left);
    preOrder(root->right);
  }
};
