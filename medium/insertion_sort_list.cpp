#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* insertionSortList(ListNode* h) {
    ListNode sentry(-1000000);
    ListNode *head = &sentry;
    head->next = h;

    ListNode *ptr = h, *cur;

    while (ptr) {
      ListNode *insert_pos = head;
      cur = ptr->next;

      bool flag = true;

      if (cur) {

        while (insert_pos != cur) {

          if (cur->val < insert_pos->next->val) {
            flag = false;
            ptr->next = cur->next;
            cur->next = insert_pos->next;
            insert_pos->next = cur;
            break;
          }

          insert_pos = insert_pos->next;
        }
      }

      if (flag)
        ptr = ptr->next;
    }

    return head->next;
  }
};

int main() {
  ListNode *head = new ListNode(3),
    *n1 = new ListNode(2),
    *n2 = new ListNode(2);
  head->next = n1;
  n1->next = n2;
  n2->next = NULL;

  Solution a;
  ListNode *travel = a.insertionSortList(head);

  while (travel) {
    std::cout << travel->val << " ";
    travel = travel->next;
  }

  return 0;
}
