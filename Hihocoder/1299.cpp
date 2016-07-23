#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int MAXN = 100100;
int intervalTree[(MAXN << 2)];

void update(int o, int l, int r, int index, int value) {
    if (index == l && index == r) {
        intervalTree[o] = max(intervalTree[o], value);
        return;
    }
    int mid = l + (r - l) / 2;
    if (index <= mid) {
        update(o * 2 + 1, l, mid, index, value);
    } else {
        update(o * 2 + 2, mid + 1, r, index, value);
    }
    intervalTree[o] = max(intervalTree[o * 2 + 1], intervalTree[o * 2 + 2]);
}

int query(int o, int l, int r, int start, int end) {
    if (start <= l && end >= r) {
        return intervalTree[o];
    }
    int mid = l + (r - l) / 2;
    if (end <= mid) {
        return query(o * 2 + 1, l, mid, start, end);
    } else if (start > mid) {
        return query(o * 2 + 2, mid + 1, r, start, end);
    }
    return max(query(o * 2 + 1, l, mid, start, mid), query(o * 2 + 2, mid + 1, r, mid + 1, end));
}

int main() {
    // freopen("input", "r", stdin);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t, v; cin >> t >> v;
        update(0, 0, 100000, t, v);
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int ret = query(0, 0, 100000, a, b);
        if (ret) {
            cout << ret << endl;
        } else {
            cout << "None" << endl;
        }
    }
    return 0;
}