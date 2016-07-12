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

const int N = 55;
const int inf = 1100;
typedef long long LL;
typedef unsigned int UI;

struct Node {
    int r, c, rain;
    Node() {
        r = c = rain = 0;
    }
    Node (int r_, int c_, int rain_) {
        r = r_;
        c = c_;
        rain = rain_;
    }
    bool operator< (const Node& n1) const {
        return rain > n1.rain;
    }
};

int matrix[N][N];
int visit[N][N];
int n, m;
priority_queue<Node> pq;

int bfs(int r, int c, int rain) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool fill = true;
    int index = 0;
    int ret = 0;
    int high = inf;
    vector<Node> q;

    memset(visit, 0, sizeof(visit));
    visit[r][c] = true;
    q.push_back(Node(r, c, rain));

    while (index < q.size()) {
        Node front = q[index++];
        int rr = front.r;
        int cc = front.c;
        int rrain = front.rain;
        for (int i = 0; i < 4; i++) {
            int nr = rr + dx[i];
            int nc = cc + dy[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                fill = false;
                continue;
            }
            if (matrix[nr][nc] <= rain) {
                if (!visit[nr][nc]) {
                    visit[nr][nc] = 1;
                    q.push_back(Node(nr, nc, matrix[nr][nc]));
                }
            } else {
                high = min(high, matrix[nr][nc]);
            }
        }
    }
    if (fill) {
        for (int i = 0; i < q.size(); i++) {
            Node node = q[i];
            int r = node.r;
            int c = node.c;
            int rrain = node.rain;
            ret += high - rrain;
            matrix[r][c] = high;
        }
    }
    return ret;
}

void clear() {
    memset(matrix, 0, sizeof(matrix));
    memset(visit, 0, sizeof(visit));
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int testcase; cin >> testcase;
    for (int kase = 1; kase <= testcase; kase++) {
        cin >> n >> m;
        clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <m ; j++ ) {
                cin >> matrix[i][j];
                pq.push(Node(i, j, matrix[i][j]));
            }
        }

        int ret = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int r = node.r;
            int c = node.c;
            int rain = node.rain;
            if (matrix[r][c] > rain) continue;
            ret += bfs(r, c, rain);
        }
        cout << "Case #" << kase << ": " << ret << endl;
    }
    return 0;
}