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
const int N = 110;
const int MOD = (1e9) + 7;

LL opt[N];

LL power(int n) {
	if (n == 0) {
		return 1;
	}
	LL half = power(n / 2);
	LL ret = (half * half) % MOD;
	if (n & 1) {
		ret = (ret << 1) % MOD;
	}
	return ret;
}

int main() {
	// freopen("input", "r", stdin);
	int n; cin >> n;
	opt[0] = 1, opt[1] = 2;
	for (int i = 2; i <= n; i++) {
		opt[i] = (opt[i - 1] + opt[i - 2]) % MOD;
	}

	cout << (power(n) - opt[n] + MOD) % MOD << endl;
	return 0;
}