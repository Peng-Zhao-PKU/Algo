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

const int N = 110;
const int M = 10100;
const int inf = 0x0f0f0f0f;
int dis[N][N];
struct Edge {
    int from, to, c;
    Edge(): from(0), to(0), c(0) {}
    Edge(int from_, int to_, int c_): from(from_), to(to_), c(c_) {}
} edges[M];

void clear() {
    memset(dis, inf, sizeof(dis));
    memset(edges, 0, sizeof(edges));
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int t; cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        clear();
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int from, to, c; cin >> from >> to >> c;
            edges[i] = Edge(from, to, c);
            dis[from][to] = min(dis[from][to], c);
            dis[to][from] = min(dis[to][from], c);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        cout << "Case #" << kase << ":" << endl;
        for (int i = 0; i < m; i++) {
            int from = edges[i].from, to = edges[i].to, c = edges[i].c;
            if (dis[from][to] < c) {
                cout << i << endl;
            }
        }
    }
	return 0;
}