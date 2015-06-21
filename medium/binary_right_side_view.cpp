#include <iostream>
#include <vector>
#include <queue>
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> ans;
    std::queue<TreeNode*> buf;
    if (root)
      buf.push(root);
    int node_num = 1;
    while (!buf.empty()) {
      int count = 0, right_node;
      for (int i = 0; i < node_num; ++i) {
        TreeNode *now = buf.front();

        if (i == node_num - 1)
          right_node = now->val;

        if (now->left) {
          buf.push(now->left);
          ++count;
        }
        if (now->right) {
          buf.push(now->right);
          ++count;
        }

        buf.pop();
      }
      ans.push_back(right_node);
      node_num = count;
    }
    return ans;
  }
};
