#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast && slow) {
      fast = fast->next;
      if (fast == NULL)
        return false;

      fast = fast->next;
      slow = slow->next;
      if (fast == slow)
        return true;

      if (fast == NULL)
        return false;
    }
  }
};
