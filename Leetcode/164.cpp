class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        const int n = nums.size();
        int minv = INT_MAX, maxv = INT_MIN;
        for (int i = 0; i < n; i++) {
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
        }
        
        int denom = (maxv - minv) / (n - 1);
        if (denom == 0) {
            denom++;
        }
        map<int, Bucket> bucket;
        for (int i = 0; i < n; i++) {
            int loc = (nums[i] - minv) / denom;
            bucket[loc].addElement(nums[i]);
        }
        
        int ret = 0;
        int last = -1;
        for (const auto& pair: bucket) {
            int loc = pair.first;
            if (last != -1) {
                ret = max(ret, bucket[loc].minv - last);
            }
            last = bucket[loc].maxv;
        }
        return ret;
    }
private:
    struct Bucket {
        int minv, maxv, cnt;
        Bucket() {
            minv = INT_MAX;
            maxv = INT_MIN;
            cnt = 0;
        }
        Bucket(int minv_, int maxv_, int cnt_): minv(minv_), maxv(maxv_), cnt(cnt_) {}
        void addElement(int x) {
            cnt++;
            minv = min(minv, x);
            maxv = max(maxv, x);
        }
    };
};