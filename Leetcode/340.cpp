class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        const int n = s.size();
        int ret = 0, start = 0;
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; i++) {
            while (cnt.size() == k && cnt.find(s[i]) == cnt.end()) {
                if (--cnt[s[start]] == 0) {
                    cnt.erase(s[start]);
                }
                start++;
            }
            cnt[s[i]]++;
            ret = max(ret, i - start + 1);
        }
        ret = max(ret, n - start);
        return ret;
    }
};