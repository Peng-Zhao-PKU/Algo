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

const int N = 550;
const int M = 2020;
const int inf = 0x0f0f0f0f;
int dis[24][N], visit[N];
int matrix[N][N][24];
int n, m, k;

void clear() {
    memset(matrix, inf, sizeof(matrix));
    memset(dis, inf, sizeof(dis));
}

void dijkstra(int t) {
    memset(visit, 0, sizeof(visit));
    dis[t][1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dis[t][1], 1));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int distance = top.first;
        int current = top.second;
        if (visit[current]) {
            continue;
        }
        visit[current] = 1;
        for (int i = 1; i <= n; i++) {
            if (dis[t][i] > distance + matrix[current][i][(t + distance) % 24]) {
                dis[t][i] = distance + matrix[current][i][(t + distance) % 24];
                pq.push(make_pair(dis[t][i], i));
            }
        }
    }
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int t; cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        clear();
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++) {
            int from, to; cin >> from >> to;
            for (int j = 0; j < 24; j++) {
                int cost; cin >> cost;
                matrix[from][to][j] = min(matrix[from][to][j], cost);
                matrix[to][from][j] = min(matrix[to][from][j], cost);
            }
        }
        for (int i = 0; i < 24; i++) {
            dijkstra(i);
        }
        cout << "Case #" << kase << ":";
        while (k--) {
            int d, s; cin >> d >> s;
            cout << " " << (dis[s][d] == inf ? -1 : dis[s][d]);
        }
        cout << endl;
    }
	return 0;
}