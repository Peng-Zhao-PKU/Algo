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

using namespace std;
const int N = 10100 * 32;

typedef unsigned int UI;

struct IP {
    UI ip, mask;
    IP(UI ip_, UI mask_): ip(ip_), mask(mask_) {}
    IP(UI a, UI b, UI c, UI d, UI mask_) {
        ip = (a << 24) + (b << 16) + (c << 8) + d;
        mask = mask_;
    }
    string toString() {
        UI a = ip >> 24;
        UI b = (ip >> 16) & 0xff;
        UI c = (ip >> 8) & 0xff;
        UI d = ip & 0xff;
        return to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d) + "/" + to_string(mask);
    }
};

struct Trie {
    int ch[N][2];
    int val[N];
    int sz;

    void clear() {
        sz = 1;
        memset(ch, 0, sizeof(ch));
        memset(val, 0, sizeof(val));
    }

    void insert(IP ip) {
        int u = 0;
        int num = ip.ip;
        int mask = ip.mask;
        for (int i = 0; i < mask; i++) {
            int test = ((1 << (31 - i)) & num) != 0;
            if (!ch[u][test]) {
                ch[u][test] = sz++;
            }
            u = ch[u][test];
        }
        val[u] = 1;
    }

    void dfs(int current) {
        if (val[current]) {
            return;
        }
        int left = ch[current][0];
        int right = ch[current][1];
        if (left) {
            dfs(left);
        }
        if (right) {
            dfs(right);
        }
        if (left && right) {
            val[current] = val[left] && val[right];
        }
    }

    void summarize(int current, UI ip, UI mask, vector<string>& ret) {
        if (val[current]) {
            ret.push_back(IP(ip, 32 - mask).toString());
            return;
        }
        int left = ch[current][0];
        int right = ch[current][1];
        if (left) {
            summarize(left, ip, mask - 1, ret);
        }
        if (right) {
            summarize(right, ip | (1 << (mask - 1)), mask - 1, ret);
        }
    }
} trie;

void clear() {
    trie.clear();
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int t = 1; t <= kase; t++) {
        clear();
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            UI a, b, c, d, m;
            scanf("%u.%u.%u.%u/%u", &a, &b, &c, &d, &m);
            trie.insert(IP(a, b, c, d, m));
        }

        trie.dfs(0);
        vector<string> ret;
        trie.summarize(0, 0, 32, ret);
        cout << "Case #" << t << ":" << endl;
        for (const string& str : ret) {
            cout << str << endl;
        }
    }
	return 0;
}