class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        n = min(n, 10);
        vector<int> opt(n + 1, 0);
        opt[1] = 10;
        for (int i = 2; i <= n; i++) {
            int temp = 1;
            for (int j = 1; j <= i; j++) {
                if (j == 1) {
                    temp *= 9;
                } else {
                    temp *= (10 - j + 1);
                }
            }
            opt[i] = temp;
        }
        
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            ret += opt[i];
        }
        return ret;
    }
};