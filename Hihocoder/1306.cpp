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
const int N = 500500;

struct Query {
	int start, end;
	int lastestPrice;
	Query(int s, int e, int lp) {
		start = s;
		end = e;
		lastestPrice = lp;
	}
};

int n;
int price[N], minv[N][20], maxv[N][20];
int timestamp[N];
vector<Query> v;

void rmq() {
	for (int i = 0; i < n; i++) {
		minv[i][0] = price[i];
		maxv[i][0] = price[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
			maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int getMin(int L, int R) {
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1) k++;
	return min(minv[L][k], minv[R - (1 << k) + 1][k]);
}

int getMax(int L, int R) {
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1) k++;
	return max(maxv[L][k], maxv[R - (1 << k) + 1][k]);
}

int main() {
	// freopen("input", "r", stdin);
	int cmds; cin >> cmds;
	int start = 0;
	for (int i = 0; i < cmds; i++) {
		char cmd; cin >> cmd;
		if (cmd == 'P') {
			int t, p; cin >> t >> p;
			timestamp[n] = t;
			price[n++] = p;
		} else if (cmd == 'R') {
			int t; cin >> t;
			while (timestamp[start] <= t) {
				start++;
			}
		} else if (cmd == 'Q') {
			v.push_back(Query(start, n - 1, price[n - 1]));
		}
	}

	rmq();

	for (const Query & q : v) {
		cout << getMax(q.start, q.end) << " " << getMin(q.start, q.end) << " " << q.lastestPrice << endl;
	}

	return 0;
}