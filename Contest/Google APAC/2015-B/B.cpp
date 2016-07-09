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
typedef long long LL;
 
const int N = 401;
const double LIMIT = 250.0;

int start[N];
int b, l, n;

void init() {
    start[0] = 1;
    for (int i = 1; i < N; i++) {
        start[i] = start[i - 1] + i - 1;
    }
}

void clear() {
}

vector<int> nextIndex(int index) {
    int row = upper_bound(start + 1, start + N, index) - start;
    int col = index - start[row - 1];
    return {index, start[row] + col, start[row] + col + 1};
}

map<int, double> bfs(double total, int level) {
    queue<pair<int, double>> current, next;
    map<int, double> nextWine;
    current.push({1, total});
    nextWine[1] = total;

    while (level > 1) {
        nextWine.clear();
        while (!current.empty()) {
            auto front = current.front();
            current.pop();
            double split = (front.second - LIMIT) / 3;
            auto indexes = nextIndex(front.first);
            for (const auto& index: indexes) {
                nextWine[index] += split;
            }
        }
        for (const auto& p : nextWine) {
            if (p.second - LIMIT > 1e-9) {
                next.push(p);
            }
        }
        level--;
        swap(current, next);
    }
    return nextWine;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    init();
    int kase; cin >> kase;
    for (int testcase = 1; testcase <= kase; testcase++) {
        clear();
        cin >> b >> l >> n;
        cout << "Case #" << testcase << ": " << fixed << setprecision(7) << min(bfs(b * 750.0, l)[n], 250.0) << endl;
    }
    return 0;
}