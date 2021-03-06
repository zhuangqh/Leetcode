#include <iostream>
#include <stack>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode *head, int n) {
    int real_index = getlength(head) - n;
    ListNode *ptr = head, *aim;
    if (real_index == 0) {
      aim = ptr->next;
      delete head;
      return aim;
    }
    int count = 1;
    while (count < real_index) {
      ptr = ptr->next;
      ++count;
    }
    aim = ptr->next;
    ptr->next = aim->next;
    delete aim;
    return head;
  }
  int getlength(ListNode *head) {
    int len = 0;
    ListNode *ptr = head;
    while (ptr) {
      ++len;
      ptr = ptr->next;
    }
    return len;
  }
};
