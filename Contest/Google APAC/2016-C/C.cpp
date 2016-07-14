#include <bits/stdc++.h>

using namespace std;

const int N = 4;
typedef long long LL;
typedef unsigned int UI;

int friends[1 << N][1 << N];
int opt[1 << (1 << N)];
vector<int> mask[1 << N];
int n, m;

// State Compression DP
// status is a number of 0 or 1, opt[status] equals whether those elves indicated by status can be lined together.
// opt[status] = all_sub_set_or(opt[s1] && opt[s2] && no elf can disturb the whole range),
// s1 and s2 have exactly half one's of status
int dfs(int status, int cnt) {
    if (opt[status] >= 0) {
        return opt[status];
    }
    if (cnt == 0) {
        return opt[status] = 1;
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = i + 1; j < (1 << n); j++) {
            if (friends[i][j] >= cnt && (status & (1 << i)) && (status & (1 << j))) {
                return opt[status] = 0;
            }
        }
    }
    int index = (1 << (cnt - 1));
    int flag = 0;
    for (int i = 0; i < mask[index].size(); i++) {
        int a = mask[index][i];
        int b = status - a;
        if (((status & a) == a) && a < b) {
            flag = dfs(a, cnt - 1) && dfs(b, cnt - 1);
        }
        if (flag) break;
    }
    return opt[status] = flag;
}

void init() {
    for (int i = 0; i < (1 << (1 << N)); i++) {
        mask[__builtin_popcount(i)].push_back(i);
    }
}

void clear() {
    memset(friends, 0, sizeof friends);
    memset(opt, -1, sizeof opt);
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    
    init();
    
    int testcase; cin >> testcase;
    for (int kase = 1; kase <= testcase; kase++) {
        clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int e, k, b; cin >> e >> k >> b;
            e--;
            for (int j = 0; j < b; j++) {
                int id; cin >> id;
                id--;
                friends[e][id] = max(friends[e][id], k);
                friends[id][e] = max(friends[id][e], k);
            }
        }
        
        cout << "Case #" << kase << ": " << (dfs((1 << (1 << n)) - 1, n) == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}