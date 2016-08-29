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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = head->val;
        int count = 1;

        ListNode *ptr = head->next;
        while (ptr) {
            ++count;
            int ran = rand() % count + 1;
            if (ran == 1) {
                ans = ptr->val;
            }
            ptr = ptr->next;
        }
        return ans;
    }
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
 