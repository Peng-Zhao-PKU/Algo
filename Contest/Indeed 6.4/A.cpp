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
 
using namespace std;
const int N = 10;
char str[N], path[N];
int cnt[N], temp[N];
vector<string> ret;
int n;
 
bool valid() {
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < n; i++) {
		temp[path[i] - 'a']++;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		ret += max(temp[i] - cnt[i], 0);
	}
	return ret <= 1;
}
 
void dfs(int cur) {
	if (cur >= n) {
		if (valid()) {
			ret.push_back(string(path, path + n));
		}
		return;
	}
 
	for (char c = 'a'; c <= 'd'; c++) {
		path[cur] = c;
		dfs(cur + 1);
		path[cur] = 0;
	}
}
 
int main() {
	// freopen("input", "r", stdin);
	cin >> str;
	n = strlen(str);
	for (int i = 0; i < n; i++) {
		cnt[str[i] - 'a']++;
	}
 
	dfs(0);
	for (int i = 0, l = ret.size(); i < l; i++) {
		cout << ret[i] << endl;
	}
	return 0;
}
