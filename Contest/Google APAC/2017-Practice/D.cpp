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
LL sum[N], ssum[N];
int n, q;

void clear() {
    memset(sum, 0, sizeof(sum));
    memset(ssum, 0, sizeof(ssum));
}

LL getSum(LL k) {
    // calc the sum of lowest kth the subarrays
    // 1. what is the kth sum of the sum of all the subarrays, log(sum[n]) * (nlogn)
    // 2. how to sum up values of lowest kth subarrays, nlogn
    LL start = 0, end = sum[n] + 1;
    while (start < end) {
        LL mid = start + (end - start) / 2; // if the kth sum is mid
        LL cnt = 0; // how many sums less or equal than mid
        for (int i = 1; i <= n; i++) {
            LL index = upper_bound(sum + i, sum + n + 1, mid + sum[i - 1]) - sum;
            cnt += (index - i);
        }
        if (cnt < k) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    LL kth = start;
    LL cnt = 0; // how many sums less than the kth
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        LL index = lower_bound(sum + i, sum + n + 1, kth + sum[i - 1]) - sum;
        cnt += (index - i);
        ret += ssum[index - 1] - ssum[i - 1] - (index - i) * sum[i - 1];
    }
    ret += (k - cnt) * kth;
    return ret;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int t; cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        clear();
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            LL num; cin >> num;
            sum[i] = sum[i - 1] + num;
            ssum[i] = sum[i] + ssum[i - 1];
        }
        cout << "Case #" << kase << ":" << endl;
        while (q--) {
            LL l, r; cin >> l >> r;
            LL ret = getSum(r) - getSum(l - 1);
            cout << ret << endl;
        }
    }
	return 0;
}