#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int N = 100100;

int degree[N], stable[N];
int sorted[N], fa[N];
vector<int> edges[N], mentor[N];

void topSort(int start) {
	int index = 0;

	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		sorted[index++] = front;
		for (int i = 0; i < edges[front].size(); i++) {
			int to = edges[front][i];
			if (--degree[to] == 0) {
				q.push(to);
			}
		}
	}
}

int findset(int x) {
	return fa[x] == x ? x : fa[x] = findset(fa[x]);
}

int main() {
    // freopen("input", "r", stdin);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
    	int k; cin >> k;
    	for (int j = 0; j < k; j++) {
    		int m; cin >> m;
    		edges[m].push_back(i);
    		mentor[i].push_back(m);
    		degree[i]++;
    		if (m == 0) {
    			stable[i] = true;
    		}
    	}
    }

    topSort(0);
    for (int i = 1; i <= n; i++) {
    	int student = sorted[i];
    	if (stable[student]) {
    		fa[student] = student;
    		continue;
    	}
    	set<int> diff;
    	for (int j = 0; j < mentor[student].size(); j++) {
    		int m = mentor[student][j];
    		diff.insert(findset(m));
    	}
    	stable[student] = diff.size() >= 2;
    	fa[student] = stable[student] ? student : findset(*diff.begin());
    }
    cout << accumulate(stable + 1, stable + n + 1, 0) << endl;
    return 0;
}