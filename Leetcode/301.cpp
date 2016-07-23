class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        const int n = s.size();
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                if (--left < 0) {
                    left = 0;
                    right++;
                }
            }
        }
        string path = "";
        vector<string> ret;
        unordered_set<string> us;
        dfs(0, left, right, 0, s, path, ret, us);
        return ret;
    }
    
    void dfs(int cur, int left, int right, int open, string& s, string path, vector<string>& ret, unordered_set<string>& us) {
        if (left < 0 || right < 0 || open < 0) {
            return;
        }
        if (cur >= s.size()) {
            if (left || right || open) {
                return;
            }
            if (us.find(path) == us.end()) {
                us.insert(path);
                ret.push_back(path);
            }
            return;
        }
        if (s[cur] == '(') {
            if (left) {
                dfs(cur + 1, left - 1, right, open, s, path, ret, us);
            }
            dfs(cur + 1, left, right, open + 1, s, path + s[cur], ret, us);
        } else if (s[cur] == ')') {
            if (right) {
                dfs(cur + 1, left, right - 1, open, s, path, ret, us);
            }
            dfs(cur + 1, left, right, open - 1, s, path + s[cur], ret, us);
        } else {
            dfs(cur + 1, left, right, open, s, path + s[cur], ret, us);
        }
    }
};