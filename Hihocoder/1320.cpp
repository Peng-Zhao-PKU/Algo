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

char str[N];
int opt[N][N];
vector<int> factors[N];
int n;

void clear() {
	memset(str, 0, sizeof(str));
	memset(opt, inf, sizeof(opt));
}

bool valid(int i, int j, int f) {
	for (int k = 0; k < f; k++) {
		int start = i + k;
		while (start <= j) {
			if (str[start] != str[i + k]) {
				return false;
			}
			start += f;
		}
	}
	return true;
}

void dp() {
	for (int i = 0; i < n; i++) {
		opt[i][i] = 1;
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			int j = i + l - 1;
			int ret = l;
			for (int k = i; k < j; k++) {
				ret = min(ret, opt[i][k] + opt[k + 1][j]);
			}
			vector<int> factor = factors[l];
			for (int f : factor) {
				if (valid(i, j, f)) {
					int count = l / f;
					int base = 0;
					while (count) {
						count /= 10;
						base++;
					}
					ret = min(ret, (base + 2 + opt[i][i + f - 1]));
				}
			}
			opt[i][j] = ret;
		}
	}
}

int main() {
	// freopen("input", "r", stdin);

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j * j <= i; j++) {
			if ((i % j) == 0) {
				int another = i / j;
				factors[i].push_back(j);
				if (another != j && another < i) {
					factors[i].push_back(another);
				}
			}
		}
	}

	int kase; cin >> kase;
	while (kase--) {
		clear();
		cin >> str;
		n = strlen(str);
		dp();
		cout << opt[0][n - 1] << endl;
	}
	return 0;
}