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
const int N = 110;
const int inf = 0x0f0f0f0f;
int n;
char str[N];
int opt[N][N];

int main() {
	// freopen("input", "r", stdin);

	cin >> str;
	n = strlen(str);
	memset(opt, inf, sizeof(opt));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			opt[i][j] = 0;
		}
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			int j = i + l - 1;
			int ret = opt[i][j];
			ret = min(ret, opt[i][j - 1] + 1);
			ret = min(ret, opt[i + 1][j] + 1);
			ret = min(ret, opt[i + 1][j - 1] + (str[i] != str[j]));
			opt[i][j] = ret;
		}
	}
	cout << opt[0][n - 1] << endl;
	return 0;
}