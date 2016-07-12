#include <bits/stdc++.h>
 
using namespace std;

typedef long long LL;
typedef unsigned int UI;
const int N = 1010;

int opt[N][N];
int A[N];
int sum[N];

int getSum(int i, int j) {
    if (i > j) return 0;
    if (i == 0) return sum[j];
    return sum[j] - sum[i - 1];
}

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    partial_sum(A, A + n, sum);
    for (int i = 0; i < n; i++) {
        opt[i][i] = A[i];
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            opt[i][j] = max(A[i] + getSum(i + 1, j) - opt[i + 1][j], A[j] + getSum(i, j - 1) - opt[i][j - 1]);
        }
    }
    cout << opt[0][n - 1] << endl;
    return 0;
}