#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* reverseList(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *ptr = head, *ppp = ptr->next;
    ptr->next = NULL;
    if (ppp == NULL) return head;
    while (ppp) {
      ListNode *tmp = ppp->next;
      ppp->next = ptr;
      ptr = ppp;
      ppp = tmp;
    }
    return ptr;
  }
};
