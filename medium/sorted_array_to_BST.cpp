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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    buf = nums;
    TreeNode *ret = array2BST(0, nums.size() - 1);

    return ret;
  }
private:
  vector<int> buf;
  TreeNode* array2BST(int l, int r) {
    if (l > r) {
      return NULL;
    } else if (l == r) {
      return new TreeNode(buf[l]);
    } else {

      int mid = (l + r) / 2;
      TreeNode *root = new TreeNode(buf[mid]);

      root->left = array2BST(l, mid - 1);
      root->right = array2BST(mid + 1, r);
    }
  }
};
