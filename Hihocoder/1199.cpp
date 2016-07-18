#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int N = 10100;

int p[N], q[N];
int cost[N], entry[N];
int visit[N];
vector<int> edges[N];
int n;

struct Node {
    int entry, cost;
    bool operator< (const Node & node) const {
        return max(entry, node.entry - cost) < max(node.entry, entry - node.cost);
    }
};

int dfs(int cur) {
    vector<Node> v;
    visit[cur] = 1;
    for (int i = 0, l = edges[cur].size(); i < l; i++) {
        int to = edges[cur][i];
        if (visit[to]) continue;
        dfs(to);
        v.push_back({entry[to], cost[to]});
    }
    sort(v.begin(), v.end());
    v.insert(v.begin(), {p[cur], q[cur] - p[cur]});
    int e = v.back().entry;
    int c = v.back().cost;
    for (int i = v.size() - 2; i >= 0; i--) {
        e = max(v[i].entry, e - v[i].cost);
        c += v[i].cost;
    }
    cost[cur] = c;
    return entry[cur] = e;
}

int main() {
    // freopen("input", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> q[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int from, to; cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    cout << dfs(1) << endl;
    return 0;
}