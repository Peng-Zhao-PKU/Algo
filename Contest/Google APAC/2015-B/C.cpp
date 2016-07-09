#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
 
using namespace std;
typedef long long LL;
 
const int N = 110;
const int MOD = (LL)(1e9) + 7;
const int inf = 0x0f0f0f0f;
int A[N];
int opt[N][N];

void clear() {
    memset(A, 0, sizeof(A));
    memset(opt, 0, sizeof(opt));
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int testcase = 1; testcase <= kase; testcase++) {
        clear();
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i, t = min(n, i + 2); j < t; j++) {
                opt[i][j] = j - i + 1;
            }
        }

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                int ret = 1 + opt[i + 1][j];
                for (int ii = i + 1; ii < j; ii++) {
                    if (A[ii] != A[i] + k) continue;
                    for (int iii = ii + 1; iii <= j; iii++) {
                        if (A[iii] != A[ii] + k) continue;
                        if (opt[i + 1][ii - 1] != 0 || opt[ii + 1][iii - 1] != 0) continue;
                        ret = min(ret, opt[iii + 1][j]);
                    }
                }
                opt[i][j] = ret;
            }
        }
        cout << "Case #" << testcase << ": " << opt[0][n - 1] << endl;
    }
    return 0;
}