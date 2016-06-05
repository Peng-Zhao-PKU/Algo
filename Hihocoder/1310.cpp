#include <cmath>
#include <cstdio>
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

const int N = 55;
char matrix[N][N];
int visit[N][N];
unordered_set<int> area;
unordered_set<string> shape;
int ret = 0;
int n, m;

void dfs(int r, int c, int l, int& a, string& s) {
	visit[r][c] = 1;
	a++;
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == '#' && !visit[nr][nc]) {
			s = s + to_string(l);
			s = s + (char)('0' + i);
			dfs(nr, nc, l + 1, a, s);
		}
	}
}

int main() {
	// freopen("input", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '#' && !visit[i][j]) {
				ret++;
				int a = 0;
				string s = "";
				dfs(i, j, 0, a, s);
				area.insert(a);
				shape.insert(s);
			}
		}
	}
	cout << ret << " " << area.size() << " " << shape.size() << endl;
	return 0;
}