class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int n = nums.size();
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                int head = 0;
                while (slow != head) {
                    slow = nums[slow];
                    head = nums[head];
                }
                return slow;
            }
        }
        return -1;
    }
};