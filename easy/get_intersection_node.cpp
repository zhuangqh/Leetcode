#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* getIntersectionNode(ListNode *heada, ListNode *headb) {
    if (!heada || !headb) return NULL;
    ListNode *pa = heada, *pb = headb;
    int lena = 0, lenb = 0;
    while (pa->next) {++lena; pa = pa->next;}
    while (pb->next) {++lenb; pb = pb->next;}
    if (pa != pb) return NULL;

    pa = heada;
    pb = headb;

    if (lena > lenb) {
      for (int i = 0; i < lena - lenb; ++i)
        pa = pa->next;
    } else {
      for (int i = 0; i < lenb - lena; ++i)
        pb= pb->next;
    }

    while (pa && pb) {
      if (pa == pb) {
        return pa;
      }
      pa = pa->next;
      pb = pb->next;
    }
  }
};
