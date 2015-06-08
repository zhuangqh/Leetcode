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
    ListNode *ptr = head, *tmp;
    while (ptr->next) {
      if (ptr->next->val == val) {
        //delete node
        tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
      } else {
        ptr = ptr->next;
      }
    }

    if (head->val == val) {
      tmp = head;
      if (head->next)
        head = head->next;
      else
        head = NULL;
      delete tmp;
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
