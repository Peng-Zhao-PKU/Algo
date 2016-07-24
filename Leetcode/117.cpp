/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = root;
        while (head) {
            TreeLinkNode *dummy = new TreeLinkNode(-1);
            TreeLinkNode *prev = dummy;
            TreeLinkNode *current = head;
            while (current) {
                if (current->left) {
                    prev->next = current->left;
                    prev = prev->next;
                }
                if (current->right) {
                    prev->next = current->right;
                    prev = prev->next;
                }
                current = current->next;
            }
            head = dummy->next;
            delete dummy;
        }
    }
};