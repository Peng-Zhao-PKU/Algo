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
const int N = 550;
vector<int> edges[N];
int visit[N];

void clear() {
	for (int i = 0; i < N; i++) {
		edges[i].clear();
	}
	memset(visit, 0, sizeof(visit));
}

int dfs(int cur, int father) {
	int ret = 1;
	visit[cur] = 1;
	for (int i = 0; i < edges[cur].size(); i++) {
		int to = edges[cur][i];
		if (!visit[to] && father != to) {
			ret += dfs(to, cur);
		}
	}
	return ret;
}

int main() {
	// freopen("input", "r", stdin);
	int t; cin >> t;
	while (t--) {
		clear();
		int n, m; cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int s, t; cin >> s >> t;
			edges[s].push_back(t);
			edges[t].push_back(s);
		}

		if (m != n - 1) {
			cout << "NO" << endl;
			continue;
		}

		if (dfs(1, 0) == n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}