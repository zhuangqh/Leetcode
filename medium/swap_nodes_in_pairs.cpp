#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* swapPairs(ListNode *head) {
    ListNode root(-1);
    ListNode *new_root, *ptr;
    new_root = ptr = &root;
    new_root->next = head;
    while (ptr->next) {
      if (ptr->next->next == NULL) {
        break;
      } else {
        ListNode *tmp = ptr->next->next;
        ptr->next->next = tmp->next;
        tmp->next = ptr->next;
        ptr->next = tmp;
        ptr = tmp->next;
      }
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
  b->next = c;
  c->next = d;
  Solution ss;
  ListNode *ptr = ss.swapPairs(a);
  while (ptr) {
    std::cout << ptr->val << std::endl;
    ptr = ptr->next;
  }
  return 0;
}
