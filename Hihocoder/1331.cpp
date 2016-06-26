#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;
typedef long long LL;

LL dfs(LL num, int pos) {
    if (num < 0) {
        return 0;
    }
    if (pos == 0) {
        return num <= 2;
    }
    LL temp = ((LL)2) << pos;
    if (num >= (temp << 1) - 1) {
        return 0;
    }
    return dfs(num, pos - 1) + dfs(num - (1 << pos), pos - 1) + (dfs(num - temp, pos - 1));
}

int main() {
    // freopen("input", "r", stdin);
    LL num; cin >> num;
    cout << dfs(num, 30) << endl;
	return 0;
}