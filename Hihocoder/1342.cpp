#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int N = (1 << 20);
vector<pii> nodes;
int bottom[22];
int level[22];

void dfs(int x, int y, int h) {
	if (h == 0) {
		return;
	}
	nodes.push_back({x, y});
	dfs(x + level[h] + 1, y + level[h] + 1, h - 1);
	dfs(x + level[h] + 1, y - level[h] - 1, h - 1);
}

int main() {
    // freopen("input", "r", stdin);
    int n; cin >> n;
    bottom[1] = 1, bottom[2] = 5;
    for (int i = 3; i <= n; i++) {
    	bottom[i] = 2 * bottom[i - 1] + 1;
    }
    level[1] = 0, level[2] = 1;
    for (int i = 3; i <= n; i++) {
    	int temp = bottom[i - 1] + 1;
    	for (int j = 0; j < i; j++) {
    		temp -= level[j];
    	}
    	level[i] = temp - i;
    }

    dfs(0, 0, n);

    int m; cin >> m;
    while (m--) {
    	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	    int ret = 0;
	    for (int i = 0, l = nodes.size(); i < l; i++) {
	    	int x = nodes[i].first;
	    	int y = nodes[i].second;
	    	if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
	    		ret++;
	    	}
	    }
	    cout << ret << endl;
    }
    return 0;
}