class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> sum(n, 0);
        unordered_map<int, int> um;
        
        partial_sum(nums.begin(), nums.end(), sum.begin());

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (sum[i] == k) {
                ret = max(ret, i + 1);
            }
            if (um.find(sum[i] - k) != um.end()) {
                ret = max(ret, i - um[sum[i] - k]);
            }
            
            if (um.find(sum[i]) == um.end()) {
                um[sum[i]] = i;
            }
        }
        return ret;
    }
};