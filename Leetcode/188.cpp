class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        vector<int> diff;
        int tot = 0;
        
        for (int i = 0; i + 1 < n; i++) {
            int d = prices[i + 1] - prices[i];
            diff.push_back(d);
            if (d > 0) {
                tot += d;
            }
        }
        if (k >= prices.size() - 1) {
            return tot;
        }
        return KSegmentSum(diff, k);
    }
    
    int KSegmentSum(vector<int>& nums, int K) {
        const int n = nums.size();
        vector<int> f(K + 1, 0), g(K + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= min(i + 1, K); j++) {
                f[j] = max(f[j], g[j - 1]) + nums[i];
            }
            for (int j = 1; j <= min(i + 1, K); j++) {
                g[j] = max(f[j], g[j]);
            }
        }
        
        int ret = 0;
        for (int i = 0; i <= K; i++) {
            ret = max(ret, g[i]);
        }
        return ret;
    } 
};