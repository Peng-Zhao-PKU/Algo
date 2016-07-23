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
public:
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 1;
        helper(root, root->val, 1, ret);
        return ret;
    }
    
    void helper(TreeNode* root, int father, int len, int& ret) {
        ret = max(ret, len);
        if (root == nullptr) {
            return;
        }
        int add = root->val == father + 1 ? len : 0;
        helper(root->left, root->val, add + 1, ret);
        helper(root->right, root->val, add + 1, ret);
    }
};