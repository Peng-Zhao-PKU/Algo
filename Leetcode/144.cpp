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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        TreeNode *current = root;
        
        while (!s.empty() || current) {
            if (current) {
                ret.push_back(current->val);
                s.push(current);
                current = current->left;
            } else {
                current = s.top();
                s.pop();
                current = current->right;
            }
        }
        return ret;
    }
};