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
  std::vector<std::vector<int> > levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int> > ans;
    std::queue<TreeNode*> buf;
    if (root)
      buf.push(root);
    int node_num = 1;
    while (!buf.empty()) {
      std::vector<int> tmp;
      int count = 0;
      for (int i = 0; i < node_num; ++i) {
        TreeNode *now = buf.front();
        tmp.push_back(now->val);

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
      ans.push_back(tmp);
      node_num = count;
    }
    return ans;
  }
};
int main() {

}
