#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
 
using namespace std;

const int N = 100010;
const int M = 1000010;
typedef long long LL;

struct Edge {
    int from, to, cost;
    Edge(): from(0), to(0), cost(0) {}
    Edge(int from_, int to_, int cost_): from(from_), to(to_), cost(cost_) {}
    bool operator < (const Edge& e) const {
        return cost < e.cost;
    }
} edges[M];
int fa[N];
int n, m;

int findset(int x) {
    return x == fa[x] ? x : fa[x] = findset(fa[x]);
}

void unionset(int fx, int fy) {
    fa[fx] = fy;
}

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int ret = 0;
    cin >> n >> m;
    iota(fa, fa + n, 0);
    for (int i = 0; i < m; i++) {
        int from, to, cost; cin >> from >> to >> cost;
        edges[i] = Edge(from, to, cost);
    }

    sort(edges, edges + m);
    for (int i = 0; i < m; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int ffrom = findset(from);
        int fto = findset(to);
        if (ffrom != fto) {
            ret += edges[i].cost;
            unionset(ffrom, fto);
        }
    }
    cout << ret << endl;
    return 0;
}