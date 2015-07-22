#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> buf;
    TreeNode* ptr = root, *r;  // use r to mark the r-sub tree which is visited

    while (ptr || !buf.empty()) {
      if (ptr != NULL) {
        buf.push(ptr);
        ptr = ptr->left;
      } else {

        ptr = buf.top();

        if (ptr->right && ptr->right != r) {
          ptr = ptr->right;
          buf.push(ptr);
          ptr = ptr->left;
        } else {
          buf.pop();
          ans.push_back(ptr->val);  // visit the node

          r = ptr;
          ptr = NULL;
        }
      }
    }

    return ans;
  }
};
