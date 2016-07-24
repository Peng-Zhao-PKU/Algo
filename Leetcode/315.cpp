// discretization & binary indexed tree
class Solution {
public:

    int sum(int x) {
        int ret = 0;
        while (x) {
            ret += BIT[x];
            x -= x & -x;
        }
        return ret;
    }
    
    void add(int x, int n) {
        while (x <= n) {
            BIT[x]++;
            x += x & -x;
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        int label = 1;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (m.find(sorted[i]) == m.end()) {
                m[sorted[i]] = label++;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = m[nums[i]];
        }

        BIT = vector<int> (n, 0);
        vector<int> ret(n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            ret[i] = sum(nums[i] - 1);
            add(nums[i], n);
        }
        return ret;
    }
private:
    vector<int> BIT;
};