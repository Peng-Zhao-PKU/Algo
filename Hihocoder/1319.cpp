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
int n, m, x, y;
int matrix[N][N];
int visit[N][N];

int bfs() {
	queue<pair<int, int> > q;
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int blocks = 0, connection = 0, num = matrix[x][y];

	q.push(make_pair(x, y));
	visit[x][y] = 1;

	while (!q.empty()) {
		auto front = q.front(); q.pop();
		int row = front.first, col = front.second;
		blocks++;

		for (int i = 0; i < 4; i++) {
			int nrow = row + dx[i];
			int ncol = col + dy[i];
			if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
				if (matrix[nrow][ncol] == num) {
					connection++;
					if (!visit[nrow][ncol]) {
						visit[nrow][ncol] = 1;
						q.push(make_pair(nrow, ncol));
					}
				}
			}
		}
	}
	return blocks * 4 - connection;
}

int main() {
	// freopen("input", "r", stdin);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << bfs() << endl;

	return 0;
}