#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>
 
 
typedef long long LL;
using namespace std;
const int N = 22;
const int inf = 0x3f3f3f3f;
 
LL opt[N][N][N][N];
int sum[N][N];
int matrix[N][N];
int h, w;
 
void init() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 && j == 0) {
				sum[i][j] = matrix[i][j];
			} else if (i == 0) {
				sum[i][j] = matrix[i][j] + sum[i][j - 1];
			} else if (j == 0) {
				sum[i][j] = matrix[i][j] + sum[i - 1][j];
			} else {
				sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
	}
 
	memset(opt, 0, sizeof(opt));
}
 
// inclusive
int weight(int i, int j, int ii, int jj) {
	if (i == 0 && j == 0) {
		return sum[ii][jj];
	} else if (i == 0) {
		return sum[ii][jj] - sum[ii][j - 1];
	} else if (j == 0) {
		return sum[ii][jj] - sum[i - 1][jj];
	} else {
		return sum[ii][jj] - sum[i - 1][jj] - sum[ii][j - 1] + sum[i - 1][j - 1];
	}
}
 
void dp() {
	for (int l = 1; l <= h; l++) {
		for (int i = 0; i + l - 1 < h; i++) {
			int ii = i + l - 1;
			for (int ll = 1; ll <= w; ll++) {
				for (int j = 0; j + ll - 1 < w; j++) {
					int jj = j + ll - 1;
					if (i == ii && j == jj) {
						continue;
					}
 
					LL ret = inf;
					for (int k = i; k < ii; k++) {
						ret = min(ret, opt[i][j][k][jj] + opt[k + 1][j][ii][jj]);
					}
					for (int k = j; k < jj; k++) {
						ret = min(ret, opt[i][j][ii][k] + opt[i][k + 1][ii][jj]);
					}
					opt[i][j][ii][jj] = ret + weight(i, j, ii, jj);
				}
			}
		}
	}
}
 
int main() {
	// freopen("input", "r", stdin);
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c; cin >> c;
			matrix[i][j] = c - '0';
		}
	}
 
	init();
	dp();
	cout << opt[0][0][h - 1][w - 1] << endl;
	return 0;
}