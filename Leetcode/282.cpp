typedef long long LL;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        string path = "";
        dfs(0, 0, num, target, path, ret, 0);
        return ret;
    }
    
    void dfs(int pos, LL cur, string& num, int target, string path, vector<string>& ret, LL mul) {
        if (pos >= num.size()) {
            if (cur == target) {
                ret.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (i > pos && num[pos] == '0') break;
            string sub = num.substr(pos, i - pos + 1);
            LL temp = stoll(sub);
            if (path.empty()) {
                dfs(i + 1, temp, num, target, sub, ret, temp);
            } else {
                dfs(i + 1, cur + temp, num, target, path + "+" + sub, ret, temp);
                dfs(i + 1, cur - temp, num, target, path + "-" + sub, ret, -temp);
                dfs(i + 1, cur - mul + mul * temp, num, target, path + "*" + sub, ret, mul * temp);
            }
        }
    }
};