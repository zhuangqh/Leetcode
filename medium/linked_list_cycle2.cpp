#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast, *slow;
    fast = slow = head;

    while (fast && slow) {
      fast = fast->next;
      if (!fast)
        return NULL;

      fast = fast->next;
      slow = slow->next;

      if (fast == slow) { // has loop
        int loopSize = 1;
        while ((fast = fast->next) != slow) {
          ++loopSize;
        }

        fast = slow = head;

        while (loopSize--) { // put fast loopSize ahead
          fast = fast->next;
        }

        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }

        return fast;
      }

      if (!fast)
        return NULL;
    }

    return NULL;
  }
};
