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
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return helper(root)[0];
    }
    
    // 0 -> ans
    // 1 -> is univalue tree
    vector<int> helper(TreeNode *root) {
        if (root == nullptr) {
            return {0, 1};
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        vector<int> ret = vector<int>(2, 0);
        ret[1] = left[1] && right[1] && (root->left == nullptr || root->left->val == root->val) && (root->right == nullptr || root->right->val == root->val);
        ret[0] = left[0] + right[0] + ret[1];
        return ret;
    }
};