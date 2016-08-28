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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *kp = head;
        ListNode *cur = head;
        int count = 1;
        
        while (count < k) {
            kp = kp->next;
            if (kp == NULL) {
                kp = head;
                k = k % count;
                count = 0;
            }
            ++count;
        }
        if (!k || count < k) return head;
        
        while (kp->next) {
            if (kp->next->next == NULL) {
                kp->next->next = head;
                head = cur->next;
                cur->next = NULL;
                break;
            } else {
                cur = cur->next;
                kp = kp->next;
            }
        }
        return head;
    }
};
