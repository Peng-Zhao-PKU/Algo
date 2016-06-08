class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const int n = envelopes.size();
        vector<int> g(n, 0), temp(n, 0);
        int i = 0, j = 0, k = 0, ret = 0;
        
        sort(envelopes.begin(), envelopes.end());
        while (i < n) {
            j = i;
            while (j < n && envelopes[j].first == envelopes[i].first) {
                j++;
            }
            for (k = i; k < j; k++) {
                temp[k] = lower_bound(g.begin(), g.begin() + ret, envelopes[k].second) - g.begin();
            }
            bool grow = false;
            for (k = j - 1; k >= i; k--) {
                int index = temp[k];
                g[index] = envelopes[k].second;
                if (index == ret) {
                    grow = true;
                }
            }
            if (grow) {
                ret++;
            }
            i = j;
        }
        return ret;
    }
};