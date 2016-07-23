class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = s.size();
        vector<int> cnt(256, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }

        vector<int> visit(256, 0);
        string ret = "";
        for (int i = 0; i < n; i++) {
            if (visit[s[i]]) {
                cnt[s[i]]--;
                continue;
            }
            while (!ret.empty() && s[i] < ret.back() && cnt[ret.back()]) {
                visit[ret.back()] = false;
                ret.pop_back();
            }
            ret.push_back(s[i]);
            visit[s[i]] = 1;
            cnt[s[i]]--;
        }
        return ret;
    }
};