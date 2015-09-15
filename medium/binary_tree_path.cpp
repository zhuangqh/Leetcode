/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<string> ans;
    void printPath(TreeNode *root, string p) {
        if (root == NULL) return;
        
        stringstream ss;
        string num;
        ss << root->val;
        ss >> num;
        p += num;

        if (root->left == NULL && root->right == NULL)
            ans.push_back(p);
        p += "->";
        printPath(root->left, p);
        printPath(root->right, p);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        printPath(root, "");
        return ans;
    }
};