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
typedef long long LL;
const int N = 1100;

struct Circle {
	LL x, y, r;
	Circle() {
		x = y = r = 0;
	}
	Circle(LL x_, LL y_, LL r_) {
		x = x_;
		y = y_;
		r = r_;
	}
} circle[N];
int visit[N];
LL w, h, n;

void clear() {
	memset(circle, 0, sizeof(circle));
	memset(visit, 0, sizeof(visit));
}

void dfs(int cur, LL& u, LL& d) {
	u = max(u, circle[cur].y + circle[cur].r);
	d = min(d, circle[cur].y - circle[cur].r);
	visit[cur] = 1;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			double dis = (circle[i].x - circle[cur].x) * (circle[i].x - circle[cur].x)
						 + (circle[i].y - circle[cur].y) * (circle[i].y - circle[cur].y);
			dis = sqrt(dis);
			if (dis <= circle[i].r + circle[cur].r) {
				visit[i] = 1;
				dfs(i, u, d);
			}
		}
	}
}

int main() {
	// freopen("input", "r", stdin);
	int kase; cin >> kase;
	while (kase--) {
		clear();
		cin >> w >> h >> n;
		for (int i = 0; i < n; i++) {
			cin >> circle[i].x >> circle[i].y >> circle[i].r;
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				LL u = circle[i].y + circle[i].r;
				LL d = circle[i].y - circle[i].r;
				dfs(i, u, d);
				if (u >= h && d <= 0) {
					flag = false;
					break;
				}
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}