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

const int N = 110;
typedef long long LL;
typedef unsigned int UI;

int n;
double C[N];

void clear() {
    memset(C, 0, sizeof(C));
}

bool isSmall(double mid) {
    double ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += C[i] * pow(mid, (double)(n - i));
    }
    ret -= C[0] * pow(mid, n);
    return ret >= 0;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int testcase; cin >> testcase;
    for (int kase = 1; kase <= testcase; kase++) {
        clear();
        cin >> n;
        for (int i = 0; i <= n; i++) {
            cin >> C[i];
        }
        LL start = 0;
        LL end = (2e10);
        while (start < end) {
            LL mid = start + (end - start) / 2;
            double dmid = double(mid);
            dmid /= 1e10;
            if (isSmall(dmid)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        double ret = (double)start / (1e10);
        ret -= 1;
        cout << "Case #" << kase << ": " << fixed << setprecision(10) << ret << endl;
    }
    return 0;
}