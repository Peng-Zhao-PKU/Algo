class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        const int n = s.size();
        const int m = words.size();
        const int l = words[0].size();
        
        vector<int> ret;
        unordered_map<string, int> toBeFound;
        for (int i = 0; i < m; i++) {
            toBeFound[words[i]]++;
        }
        
        for (int i = 0; i < l; i++) {
            unordered_map<string, int> cnt;
            int found = 0, contains = 0, start = i;
            for (int j = i; j < n; j += l) {
                string sub = s.substr(j, l);
                contains++;
                if (++cnt[sub] <= toBeFound[sub]) {
                    found++;
                }
                while (found == m) {
                    string sub = s.substr(start, l);
                    if (cnt[sub] > toBeFound[sub]) {
                        cnt[sub]--;
                        contains--;
                        start += l;
                    } else break;
                }
                if (found == m && contains == m) {
                    ret.push_back(start);
                }
            }
        }
        return ret;
    }
};