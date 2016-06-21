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

LL dfs(int n, int x, int y, bool right) {
    if (n == 0) {
        return 1;
    }
    LL half = (1 << (n - 1));
    LL area = half * half;

    if (x <= half && y <= half) {
        return area * (right ? 3 : 0) + dfs(n - 1, half - y + 1, x, !right);
    } else if (x <= half && y > half) {
        return area * (right ? 2 : 1) + dfs(n - 1, x, y - half, right);
    } else if (x > half && y > half) {
        return area * (right ? 1 : 2) + dfs(n - 1, x - half, y - half, right);
    } else {
        return area * (right ? 0 : 3) + dfs(n - 1, y, (half << 1) - x + 1, !right);
    }
}

int main() {
    int n, x, y; cin >> n >> x >> y;
    cout << dfs(n, x, y, false) << endl;

	return 0;
}