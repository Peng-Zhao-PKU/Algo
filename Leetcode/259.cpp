class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ret = 0;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; i--) {
            int ntarget = target - nums[i];
            int start = 0, end = i - 1;
            while (start < end) {
                if (nums[start] + nums[end] < ntarget) {
                    ret += end - start;
                    start++;
                } else {
                    end--;
                }
            }
        }
        return ret;
    }
};