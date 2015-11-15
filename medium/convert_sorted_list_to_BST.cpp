/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-11-16 01:02:03
 */

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		return buildBST(head, NULL);
	}
	// build a BST from list which begin with 'start'
	// and end in 'end'
	TreeNode* buildBST(ListNode* start, ListNode* end) {
		if (!start || start == end) return NULL;
		TreeNode* ptr = findMid(start, end);
		TreeNode* root = new TreeNode(ptr->val);
		root->left = buildBST(start, ptr);
		root->right = buildBST(ptr->next, end);
	}
	TreeNode* findMid(ListNode* left, ListNode* right) {
		if (!left || left == right) return NULL;
		ListNode *fast, *slow;
		fast = slow = left;
		while ((fast = fast->next) != right) {
			fast = fast->next;
			slow = slow->next;
			if (fast = right) break;
		}

		return slow;
	}
};