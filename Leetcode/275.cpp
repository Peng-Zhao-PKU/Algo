class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        int start = 0, end = n + 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid == 0 || citations[n - mid] >= mid) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start - 1;
    }
};