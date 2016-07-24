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
    void check(TreeNode *prev, TreeNode *current) {
        if (prev == nullptr) {
            return;
        }
        if (prev->val < current->val) {
            return;
        }
        if (first == nullptr) {
            first = prev;
        }
        second = current;
    }

    void recoverTree(TreeNode* root) {
        TreeNode *current = root;
        TreeNode *prev = nullptr;
        
        while (current != nullptr) {
            if (current->left == nullptr) {
                check(prev, current);
                prev = current;
                current = current->right;
            } else {
                TreeNode *temp = current->left;
                while (temp->right != nullptr && temp->right != current) {
                    temp = temp->right;
                }
                if (temp->right == nullptr) {
                    temp->right = current;
                    current = current->left;
                } else {
                    temp->right = nullptr;
                    check(prev, current);
                    prev = current;
                    current = current->right;
                }
            }
        }
        swap(first->val, second->val);
    }
private:
    TreeNode *first = nullptr, *second = nullptr;
};