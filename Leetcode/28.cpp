class Solution {
public:
    int strStr(string haystack, string needle) {
        const int m = haystack.size();
        const int n = needle.size();
        vector<int> next = getNext(needle);
        
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++, j++;
            } else {
                j = next[j];
            }
        }
        return (j >= n) ? i - j : -1;
    }
    
    vector<int> getNext(string& str) {
        const int n = str.size();
        vector<int> next(n + 1, 0);
        next[0] = -1;
        
        int j = 0, k = -1;
        while (j < n - 1) {
            if (k == -1 || str[j] == str[k]) {
                ++j, ++k;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
        return next;
    }
};
