#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;
typedef long long LL;

const int N = 110;
const LL inf = (LL)(1e15);
struct P {
    LL p, k;
} percentage[N];

void clear() {
    memset(percentage, 0, sizeof(percentage));
}

int main() {
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int t = 1; t <= kase; t++) {
        clear();
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> percentage[i].p >> percentage[i].k;
        }

        bool flag = true;
        LL start = 0, end = inf;
        for (int i = 0; i < n; i++) {
            LL s = 0, e = inf;
            LL p = percentage[i].p, k = percentage[i].k;
            if (p == 100) {
                s = e = k;
            }
            else if (p) {
                s = 100 * k / (p + 1) + 1;
                e = min(e, 100 * k / p);
            }
            else {
                s = 100 * k / (p + 1) + 1;
            }
            if (s > end || e < start || s > e) {
                flag = false;
                break;
            }
            start = max(start, s);
            end = min(end, e);
        }
        if (start != end) {
            flag = false;
        }
        cout << "Case #" << t << ": " << (flag ? start : -1) << endl;
    }

    return 0;
}
