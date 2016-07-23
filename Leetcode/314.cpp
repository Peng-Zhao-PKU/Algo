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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        map<int, map<int, vector<int>>> m;
        dfs(root, 0, 0, m);
        for (const auto& level : m) {
            vector<int> temp;
            const auto& mm = level.second;
            for (const auto& v : mm) {
                for (const auto& val : v.second) {
                    temp.push_back(val);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
    
    void dfs(TreeNode* root, int level, int h, map<int, map<int, vector<int>>>& m) {
        if (root == nullptr) {
            return;
        }
        m[level][h].push_back(root->val);
        dfs(root->left, level - 1, h + 1, m);
        dfs(root->right, level + 1, h + 1, m);
    }
};