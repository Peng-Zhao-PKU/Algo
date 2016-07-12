#include <bits/stdc++.h>
 
using namespace std;

const int N = 20;
const int M = 15;
typedef long long LL;
typedef unsigned int UI;

int K[N], L[N];
LL A[N][M], C[N][M], SC[N][M];
LL ret = 0;

void clear() {
    memset(K, 0, sizeof(K));
    memset(L, 0, sizeof(L));
    memset(A, 0, sizeof(A));
    memset(C, 0, sizeof(C));
    memset(SC, 0, sizeof(SC));
    ret = 0;
}

void dfs(int mask, int cur, LL m, int n, LL sa) {
    if (cur >= n) {
        ret = max(ret, sa);
        return;
    }
    if ((mask & (1 << cur)) == 0) {
        dfs(mask, cur + 1, m, n, sa);
        return;
    }
    LL limit = 0;
    for (int i = cur; i < n; i++) {
        if (mask & (1 << cur)) {
            limit += A[i][K[i] - 1];
        }
    }
    if (sa + limit <= ret) {
        return;
    }
    // i = L[cur] - 1 <=> Not to upgrade and get the orginal attack power
    for (int i = K[cur] - 1; i >= L[cur] - 1; i--) {
        if (m >= SC[cur][i]) {
            dfs(mask, cur + 1, m - SC[cur][i], n, sa + A[cur][i]);
        }
    }
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int testcase; cin >> testcase;
    for (int kase = 1; kase <= testcase; kase++) {
        clear();

        int m, n;
        cin >> m >> n;

        for (int i = 0; i < n; i++) {
            cin >> K[i] >> L[i];
            for (int j = 0; j < K[i]; j++) {
                cin >> A[i][j];
            }
            for (int j = 0; j < K[i] - 1; j++) {
                cin >> C[i][j];
            }
            for (int j = 1, temp = 0; j < K[i]; j++) {
                if (j < L[i]) continue;
                temp += C[i][j - 1];
                SC[i][j] = temp;
            }
        }

        for (int x = (1 << 8) - 1; x < (1 << n); ) {
            dfs(x, 0, m, n, 0);
            int bb = x & -x;
            int cc = x + bb;
            int tt = cc & -cc;
            int mm = (tt / bb >> 1) - 1;
            x = mm | cc;
        }
        cout << "Case #" << kase << ": " << ret << endl;
    }
    return 0;
}