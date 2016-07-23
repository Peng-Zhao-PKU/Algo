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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        init(root, target);
        
        vector<int> ret;
        while (k--) {
            if (predecessor.empty() ||
                (!successor.empty() &&
                fabs(predecessor.top()->val * 1.0 - target) > fabs(successor.top()->val * 1.0 - target))) {
                ret.push_back(successor.top()->val);
                getSuccessor();
            } else {
                ret.push_back(predecessor.top()->val);
                getPredecessor();
            }
        }
        return ret;
    }
    
    void init(TreeNode* root, double target) {
        while (root) {
            if (root->val * 1.0 < target) {
                predecessor.push(root);
                root = root->right;
            } else {
                successor.push(root);
                root = root->left;
            }
        }
    }
    
    void getSuccessor() {
        TreeNode *root = successor.top();
        successor.pop();
        TreeNode *temp = root->right;
        while (temp) {
            successor.push(temp);
            temp = temp->left;
        }
    }

    void getPredecessor() {
        TreeNode *root = predecessor.top();
        predecessor.pop();
        TreeNode *temp = root->left;
        while (temp) {
            predecessor.push(temp);
            temp = temp->right;
        }
    }
private:
    stack<TreeNode*> predecessor, successor;
};