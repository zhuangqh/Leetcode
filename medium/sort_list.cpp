#include <iostream>
#include <vector>
#include <algorithm>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  static bool cmp(const ListNode* a, const ListNode* b) {
    return a->val < b->val;
  }
  ListNode* sortList(ListNode* head) {
    std::vector<ListNode*> store;
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    while (head) {
      store.push_back(head);
      head = head->next;
    }
    std::sort(store.begin(), store.end(), cmp);
    head = store[0];
    for (std::vector<ListNode*>::iterator it = ++store.begin();
         it != store.end(); ++it) {
      head->next = *it;
      head = *it;
    }
    return store[0];
  }
};
