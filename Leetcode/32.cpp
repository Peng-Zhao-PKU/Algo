class Solution {
public:
    int longestValidParentheses(string str) {
        const int n = str.size();
        int ret = 0;
        int last = -1;
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                s.push(i);
                if (last == -1) {
                    last = i;
                }
            } else {
                if (s.empty()) {
                    if (last != -1) {
                        ret = max(ret, i - last);
                    }
                    last = -1;
                } else {
                    s.pop();
                    if (s.empty()) {
                        ret = max(ret, i - last + 1);
                    } else {
                        ret = max(ret, i - s.top());
                    }
                }
            }
        }
        return ret;
    }
};