#include <bits/stdc++.h>
 
using namespace std;

typedef long long LL;
typedef unsigned int UI;
const int N = 660;

double opt[N];

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= 6; i++) {
        opt[i] = 1.0 / 6;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            double temp = 0;
            for (int k = 1; k <= 6; k++) {
                if (j - k > 0) {
                    temp += opt[j - k];
                }
            }
            opt[j] = temp / 6.0;
        }
    }
    cout << fixed << setprecision(2) << opt[m] * 100 << endl;
    return 0;
}