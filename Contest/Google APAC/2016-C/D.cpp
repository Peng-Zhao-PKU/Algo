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
#include <deque>

using namespace std;
typedef long long LL;

const int N = 3030;
LL matrix[N][N], maxv[N][N], mmaxv[N][N];
LL A[N], B[N];
struct Node {
    int r, c;
    LL num;
    Node(int r_, int c_, LL num_): r(r_), c(c_), num(num_) {}
};

void clear() {
    memset(matrix, 0, sizeof(matrix));
    memset(maxv, 0, sizeof(maxv));
    memset(mmaxv, 0, sizeof(mmaxv));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
}

int main() {
	freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int t = 1; t <= kase; t++) {
        clear();
        int n, k;
        LL c, x;
        cin >> n >> k >> c >> x;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (A[i] * (i + 1) + B[j] * (j + 1) + c) % x;
            }
        }
        for (int i = 0; i < n; i++) {
            deque<Node> d;
            for (int j = 0; j < k; j++) {
                while (!d.empty() && matrix[i][j] > d.back().num) {
                    d.pop_back();
                }
                d.push_back(Node(i, j, matrix[i][j]));
            }
            maxv[i][0] = d.front().num;

            for (int j = k; j < n; j++) {
                while (!d.empty() && matrix[i][j] > d.back().num) {
                    d.pop_back();
                }
                while (!d.empty() && j - d.front().c >= k) {
                    d.pop_front();
                }
                d.push_back(Node(i, j, matrix[i][j]));
                maxv[i][j - k + 1] = d.front().num;
            }
        }

        for (int j = 0; j <= n - k; j++) {
            deque<Node> d;
            for (int i = 0; i < k; i++) {
                while (!d.empty() && maxv[i][j] > d.back().num) {
                    d.pop_back();
                }
                d.push_back(Node(i, j, maxv[i][j]));
            }
            mmaxv[0][j] = d.front().num;

            for (int i = k; i < n; i++) {
                while (!d.empty() && maxv[i][j] > d.back().num) {
                    d.pop_back();
                }
                while (!d.empty() && i - d.front().r >= k) {
                    d.pop_front();
                }
                d.push_back(Node(i, j, maxv[i][j]));
                mmaxv[i - k + 1][j] = d.front().num;
            }
        }

        LL ret = 0;
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                ret += mmaxv[i][j];
            }
        }
        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;
}
