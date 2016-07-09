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
 
const int N = 55;
const int inf = 0x0f0f0f0f;
 
char matrix[N][N];
int visit[N][N];
int r, c;
int tot = 0;
 
vector<pair<int, int>> tbd;
 
void clear() {
    tbd.clear();
    memset(matrix, 0, sizeof matrix);
}
 
void fillAll(int rrr, int ccc) {
    queue<pair<int, int>> q;
    q.push({rrr, ccc});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int rr = front.first;
        int cc = front.second;
        visit[rr][cc] = 1;
 
        if (matrix[rr][cc] == 'R') cc++;
        else rr++;
 
        if (rr >= 0 && rr < r && cc >= 0 && cc < c) {
            q.push({rr, cc});
        }
    }
}
 
int bfs() {
    int ret = 0;
    memset(visit, 0, sizeof visit);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visit[i][j]) {
                ret++;
                fillAll(i, j);
            }
        }
    }
    return ret;
}
 
int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    cin >> r >> c;
 
    int q = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '?') {
                tbd.push_back({i, j});
                q++;
            }
        }
    }
    for (int i = 0; i < (1 << q); i++) {
        for (int j = 0; j < q; j++) {
            int test = i & (1 << j);
            int rr = tbd[j].first;
            int cc = tbd[j].second;
            if (test) {
                matrix[rr][cc] = 'R';
            } else {
                matrix[rr][cc] = 'C';
            }
        }
        tot += bfs();
    }
 
    cout << fixed << setprecision(10) << tot * 1.0 / (1 << q) << endl;
 
    return 0;
}