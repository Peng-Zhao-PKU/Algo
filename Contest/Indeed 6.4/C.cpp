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
const int N = 110;
vector<int> edges[N];
int visit[N];
int v, q;
 
int bfs(int start, int end) {
	memset(visit, 0, sizeof(visit));
	queue<int> current, next;
	current.push(start);
	visit[start] = 1;
	int ret = 0;
 
	while (!current.empty()) {
		while (!current.empty()) {
			int front = current.front();
			if (front == end) {
				return ret;
			}
			current.pop();
			for (int i = 0; i < edges[front].size(); i++) {
				int to = edges[front][i];
				if (!visit[to]) {
					visit[to] = 1;
					next.push(to);
				}
			}
		}
		swap(current, next);
		ret++;
	}
	return -1;
}
 
int main() {
	// freopen("input", "r", stdin);
	scanf("%d%d", &v, &q);
	for (int i = 1; i < v; i++) {
		edges[i].push_back(i + 1);
	}
 
	while (q--) {
		int a, b; scanf("%d%d", &a, &b);
		cout << bfs(a, b) << endl;
		edges[a].push_back(b);
	}
	return 0;
}
