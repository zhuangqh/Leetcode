/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-11-01 10:26:07
 */
#include <iostream>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root == NULL)
      return;

    TreeLinkNode* ptr = NULL;

    if (root->left) {
      root->left->next = root->right;
      if (root->right == NULL) {
        ptr = root->next;

        while (ptr) {
          if (ptr->left) {
            root->left->next = ptr->left;
            break;
          }
          if (ptr->right) {
            root->left->next = ptr->right;
            break;
          }

          ptr = ptr->next;
        }
      }
    }

    if (root->right) {
      root->right->next = NULL;
      ptr = root->next;

      while (ptr) {
        if (ptr->left) {
          root->right->next = ptr->left;
          break;
        }
        if (ptr->right) {
          root->right->next = ptr->right;
          break;
        }

        ptr = ptr->next;
      }
    }

    connect(root->left);
    connect(root->right);
  }
};

int main() {
  return 0;
}