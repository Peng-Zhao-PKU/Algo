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
    int largestBSTSubtree(TreeNode* root) {
        return helper(root)[0];
    }
    
    // 0 -> ans
    // 1 -> left maxv
    // 2 -> right minv
    // 3 -> is bst
    // 4 -> node num
    vector<int> helper(TreeNode *root) {
        if (root == nullptr) {
            return {0, INT_MIN, INT_MAX, 1, 0};
        }
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        auto ret = vector<int> (5, 0);
        ret[4] = left[4] + right[4] + 1;
        ret[3] = left[3] && right[3] && (root->val > left[1]) && (root->val < right[2]);
        ret[1] = max(root->val, max(left[1], right[1]));
        ret[2] = min(root->val, min(left[2], right[2]));
        ret[0] = max(left[0], max(right[0], (ret[3] ? ret[4] : 0)));

        return ret;
    }
};