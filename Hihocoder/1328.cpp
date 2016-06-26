#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

const int N = 110;
const int K = 6;
const int inf = N * N;

struct Point {
    int r, c;
    Point(): r(0), c(0) {}
    Point(int r_, int c_): r(r_), c(c_) {}
} keys[K];

struct Node {
    int r, c, key;
    int cost;
    Node(): r(0), c(0), key(0), cost(0) {}
    Node(int r_, int c_, int key_, int cost_): r(r_), c(c_), key(key_), cost(cost_) {}
};

char maze[N][N];
bool visit[N][N][(1 << K)];

int sr, sc, er, ec;
int n, m, k;
int ret = inf;

void bfs() {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    queue<Node> current, next;

    int status = 0;
    for (int i = 0; i < k; i++) {
        if (keys[i].r == sr && keys[i].c == sc) {
            status |= (1 << i);
            break;
        }
    }

    current.push(Node(sr, sc, status, 0));
    visit[sr][sc][status] = true;

    while (!current.empty()) {
        while (!current.empty()) {
            Node node = current.front();
            current.pop();

            if (node.r == er && node.c == ec) {
                ret = min(ret, node.cost);
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nr = node.r + dx[i];
                int nc = node.c + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] != '#') {
                    int status = node.key;
                    for (int j = 0; j < k; j++) {
                        if (keys[j].r == nr && keys[j].c == nc) {
                            status |= (1 << j);
                            break;
                        }
                    }
                    if (maze[nr][nc] == '.' || (status & (1 << (maze[nr][nc] - 'A')))) {
                        if (!visit[nr][nc][status]) {
                            // cout << "current: (" << node.r << ", " << node.c << ") next: (" << nr << ", " << nc << ")" << endl;
                            // cout << "current status: " << node.key << ", next status: " << status << ", cost: " << node.cost << endl;
                            visit[nr][nc][status] = true;
                            next.push(Node(nr, nc, status, node.cost + 1));
                        }
                    }
                }
            }
        }
        swap(current, next);
    }
}

int main() {
    // freopen("input", "r", stdin);
    cin >> n >> m >> k >> sr >> sc >> er >> ec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        keys[i] = Point(r, c);
    }

    bfs();
    cout << (ret >= inf ? -1 : ret) << endl;
	return 0;
}