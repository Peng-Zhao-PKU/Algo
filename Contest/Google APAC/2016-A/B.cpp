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

using namespace std;
typedef long long LL;

const int N = 200200;
double sum[N];

void clear() {
    memset(sum, 0, sizeof(sum));
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int t; cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            double num; cin >> num;
            sum[i] = sum[i - 1] + log(num);
        }
        cout << "Case #" << kase << ":" << endl;
        while (m--) {
            int l, r; cin >> l >> r;
            r++;
            double ret = exp((sum[r] - sum[l]) / (r - l));
            cout << fixed << setprecision(7) << ret << endl;
        }
    }
	return 0;
}