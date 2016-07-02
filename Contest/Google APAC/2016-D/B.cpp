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

void clear() {
    memset(v, 0, sizeof(v));
    memset(ballons, 0, sizeof(ballons));
}

int getTime(int p, int v) {
    if (v == 0) {
        return inf;
    }
    if (p * v > 0) {
        return inf;
    }
    return ceil(fabs(p * 1.0 / v));
}

int getEnergy(int time) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int temp = inf;
        for (int j = 0; j < m; j++) {
            if (getTime(ballons[i].p, v[j]) <= time) {
                temp = min(temp, abs(ballons[i].h - j));
            }
        }
        ret += temp;
    }
    return ret;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int t = 1; t <= kase; t++) {
        cin >> n >> m >> q;
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++) {
            int p, h; cin >> p >> h;
            ballons[i] = Ballon(p, h);
        }
        int start = 0, end = inf;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (getEnergy(mid) > q) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        if (start == inf) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << start << endl;
        }
    }
	return 0;
}