#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int N = 330;

typedef long long LL;
typedef unsigned int UI;

int n;
int cnt[N][N];
char matrix[N][N];
int visit[N][N];

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};

void clear() {
    memset(matrix, 0, sizeof(matrix));
    memset(cnt, 0, sizeof(cnt));
    memset(visit, 0, sizeof(visit));
}

void bfs(int r, int c, int& tot) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = 1;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;
        tot--;

        // cout << x << " " << y << endl;
        if (cnt[x][y] > 0) continue;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] == '.') {
                // cout << nx << " " << ny << " " << matrix[nx][ny] << endl;
                if (!visit[nx][ny]) {
                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    tot++;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int testCase = 1; testCase <= kase; testCase++) {
        clear();
        cin >> n;

        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                tot += matrix[i][j] == '.';
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '.') {
                    for (int k = 0; k < 8; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            cnt[i][j] += matrix[ni][nj] == '*';
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt[i][j] == 0 && !visit[i][j] && matrix[i][j] == '.') {
                    // cout << i << " " << j << " " << cnt[i][j] << " " << visit[i][j] << endl;
                    bfs(i, j, tot);
                    // cout << tot << endl;
                }
            }
        }

        cout << "Case #" << testCase << ": " << tot << endl;
    } 
}
