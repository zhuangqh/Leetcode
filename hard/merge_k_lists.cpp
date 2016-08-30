/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;

        int curSize = lists.size();
        int step = curSize / 2;
        while (step) {
            for (int i = 0; i < step; ++i) {
                lists[i] = mergeTwo(lists[i], lists[curSize - 1 - i]);
            }
            curSize = (curSize + 1) / 2;
            step = curSize / 2;
        }
        return lists[0];
    }
    ListNode* mergeTwo(ListNode *l1, ListNode *l2) {
        ListNode root(0);
        ListNode *head = &root;
        ListNode *cur = &root;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) {
            cur->next = l1;
        } else {
            cur->next = l2;
        }
        return head->next;
    }
};
