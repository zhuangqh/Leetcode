#include <iostream>
#include <vector>

using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

//  Time : O(n), Space : O(n)
// class Solution {
// public:
//   bool isPalindrome(ListNode *head) {
//     if (head == NULL) return true;
//     vector<int> vec;

//     while (head) {
//       vec.push_back(head->val);
//       head = head->next;
//     }

//     for (int i = 0; i < vec.size() / 2; ++i) {
//       if (vec[i] != vec[vec.size() - 1 - i])
//         return false;
//     }

//     return true;
//   }
// };
