#include <vector>
#include <stack>
#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::stack<TreeNode*> buf;
    std::vector<int> ans;
    TreeNode *ptr = root;
    while (ptr || !buf.empty()) {
      if (ptr != NULL) {
        buf.push(ptr);
        ptr = ptr->left;
      } else {
        ptr = buf.top();
        ans.push_back(ptr->val);
        ptr = ptr->right;
        buf.pop();
      }
    }
    return ans;
  }
};
