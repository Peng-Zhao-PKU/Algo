class Solution {
public:
    string longestPalindrome(string& s) {
        if (s.empty()) {
            return "";
        }
        return mancher(s);
    }
    
    string mancher(string& str) {
        const int n = str.size();
        string sstr = "$#";
        for (int i = 0; i < n; i++) {
            sstr = sstr + (char)(str[i]) + "#";
        }
        
        vector<int> p(2 * n + 10, 0);
        int id = 0, mx = 0, ret = 0, pos = 0;
        for (int i = 1; i < sstr.size(); i++) {
            int j = i < mx ? min(mx - i, p[2 * id - i]) : 0;
            while (sstr[i + j] == sstr[i - j]) j++;
            p[i] = j;
            
            if (p[i] > mx) {
                id = i;
                mx = i + p[i];
            }
            if (p[i] > ret) {
                ret = p[i];
                pos = i;
            }
        }
        return str.substr((pos - ret) / 2, ret - 1);
    }
};