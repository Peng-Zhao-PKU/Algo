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
LL opt[N][N];
int n, m;

void clear() {
    memset(opt, 0, sizeof(opt));
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int testcase = 1; testcase <= kase; testcase++) {
        clear();
        cin >> m >> n;
        opt[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                opt[i][j] = (opt[i - 1][j] * j + opt[i - 1][j - 1] * (m - j + 1)) % MOD;
            }
        }
        cout << "Case #" << testcase << ": " << opt[n][m] << endl;
    }
    return 0;
}