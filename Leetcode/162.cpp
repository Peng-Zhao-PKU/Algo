class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        int start = 0, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid == 0 || nums[mid - 1] > nums[mid]) {
                end = mid;
            } else if (mid == n - 1 || nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return start == 0 ? 0 : start - 1;
        
    }
};