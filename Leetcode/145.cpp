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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *current = root;
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        vector<int> ret;

        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current->left;
            } else {
                current = s.top();
                if (current->right == nullptr || current->right == prev) {
                    ret.push_back(current->val);
                    s.pop();
                    prev = current;
                    current = nullptr;
                } else {
                    current = current->right;
                }
            }
        }
        return ret;
    }
};