#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode root = ListNode(-1);
    ListNode *new_root, *ptr;
    new_root = ptr = &root;
    while (l1 || l2) {
      int value1 = (l1 ? l1->val : 10000),
        value2 = (l2 ? l2->val : 10000);
      ListNode *tmp = new ListNode(0);
      if (value1 <= value2) {
        tmp->val = value1;
        if (l1)
          l1 = l1->next;
      } else {
        tmp->val = value2;
        if (l2)
          l2 = l2->next;
      }

      ptr->next = tmp;
      ptr = tmp;
    }
    return new_root->next;
  }
};

int main() {
  ListNode *a = new ListNode(1),
    *b = new ListNode(2),
    *c = new ListNode(3),
    *d = new ListNode(4);
  a->next = b;
  c->next = d;
  Solution ss;
  ListNode *ptr = ss.mergeTwoLists(a, c);
  while (ptr) {
    std::cout << ptr->val << std::endl;
    ptr = ptr->next;
  }
  return 0;
}
