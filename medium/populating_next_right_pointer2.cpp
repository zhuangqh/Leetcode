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
    TreeLinkNode* now, tail, head;

    now = root;
    head = tail = NULL;  // head and tail are pointers in next level

    while (now) {
      if (now->left) {
        if (tail)
          tail = tail->next = now->left;
        else
          head = tail = now->left;
      }
      if (now->right) {
        if (tail)
          tail = tail->next = now->right;
        else
          head = tail = now->right;
      }

      if (!(now = now->next)) {
        now = head;
        head = tail = NULL;
      }
    }
  }
};

int main() {
  return 0;
}