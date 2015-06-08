#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* removeElements(ListNode *head, int val) {
    if (head == NULL) return NULL;
    ListNode *cur = head, *next = cur->next;
    while (next) {
      if (next->val == val) {
        cur->next = next->next;
        delete next;
        next = cur->next;
      } else {
        cur = cur->next;
        next = next->next;
      }
    }
    if (head->val == val) {
      cur = head;
      head = head->next;
      delete cur;
    }
    return head;
  }
};

void print(ListNode *head) {
  if (head == NULL) {
    return;
  } else {
    ListNode *ptr = head;
    while (ptr) {
      std::cout << ptr->val << std::endl;
      ptr = ptr->next;
    }
  }
}
int main() {
  Solution a;
  ListNode *aa = new ListNode(1), *bb = new ListNode(1);
  aa->next = bb;
  print(aa);
  print(a.removeElements(aa, 1));
  return 0;
}
