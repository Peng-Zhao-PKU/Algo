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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q)[0];
    }
    
    // 0 -> ans
    // 1 -> has p
    // 2 -> has q
    vector<TreeNode *> helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return {nullptr, nullptr, nullptr};
        }
        auto left = helper(root->left, p, q);
        auto right = helper(root->right, p, q);
        vector<TreeNode *> ret = {nullptr, nullptr, nullptr};
        if (left[1] || right[1] || root == p) {
            ret[1] = root;
        }
        if (left[2] || right[2] || root == q) {
            ret[2] = root;
        }
        if (left[0] || right[0] || (ret[1] != nullptr && ret[2] != nullptr)) {
            if (left[0]) {
                ret[0] = left[0];
            } else if (right[0]) {
                ret[0] = right[0];
            } else {
                ret[0] = root;
            }
        }
        return ret;
    }
};