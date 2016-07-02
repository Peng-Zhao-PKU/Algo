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
const int inf = 0x0f0f0f0f;

int r, c;
int matrix[N][N], visit[N][N];

void clear() {
    memset(matrix, 0, sizeof(matrix));
}

void fill(int rr, int cc) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push({rr, cc});
    visit[rr][cc] = 1;
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            if (nx >=0 && nx < r && ny >= 0 && ny < c) {
                if (!visit[nx][ny] && matrix[nx][ny]) {
                    visit[nx][ny] = 1;
                    q.push({nx ,ny});
                }
            }
        }
    }
}

int bfs() {
    memset(visit, 0, sizeof(visit));

    int ret = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visit[i][j] && matrix[i][j]) {
                ret++;
                fill(i, j);
            }
        }
    }
    return ret;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int t = 1; t <= kase; t++) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch; cin >> ch;
                matrix[i][j] = ch - '0';
            }
        }

        cout << "Case #" << t << ":" << endl;
        int n; cin >> n;
        while (n--) {
            char cmd; cin >> cmd;
            if (cmd == 'M') {
                int rr, cc;
                char ch;
                cin >> rr >> cc >> ch;
                matrix[rr][cc] = ch - '0';
            } else {
                cout << bfs() << endl;
            }
        }
    }
	return 0;
}