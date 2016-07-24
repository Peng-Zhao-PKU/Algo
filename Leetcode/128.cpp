class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        unordered_set<int> visit;
        for (const int& num: nums) {
            us.insert(num);
        }
        
        int ret = 0;
        for (const int& num: nums) {
            int i = 0, j = -1;
            while (us.find(num + i) != us.end() && visit.find(num + i) == visit.end()) {
                visit.insert(num + i);
                i++;
            }
            while (us.find(num + j) != us.end() && visit.find(num + j) == visit.end()) {
                visit.insert(num + j);
                j--;
            }
            ret = max(ret, i - j - 1);
        }
        return ret;
    }
};