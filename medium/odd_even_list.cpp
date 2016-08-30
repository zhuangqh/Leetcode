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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *cur = head;
        ListNode *begin = head;
        int count = 1;
        
        while (cur && cur->next) {
            if (count % 2 == 0) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = begin->next;
                begin->next = tmp;
                begin = tmp;
                ++count;
            }
            cur = cur->next;
            ++count;
        }
        return head;
    }
};
