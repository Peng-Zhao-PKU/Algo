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

typedef long long LL;
using namespace std;
const int N = 15;

unordered_map<string, LL> um;
unordered_map<LL, string> rum;
char str[N];
int n;
LL M;

string operate() {
	char c = str[0];
	int first = str[0] - '0';
	for (int i = 1; i < first; i++) {
		str[i - 1] = str[i];
	}
	str[first - 1] = c;

	return string(str, str + n);
}

int main() {
	// freopen("input", "r", stdin);
	cin >> str >> M;
	n = strlen(str);

	bool flag = false;
	for (LL i = 1; i <= M; i++) {
		string temp = operate();
		if (um.find(temp) != um.end()) {
			flag = true;
			LL j = um[temp];
			cout << rum[(M - j) % (i - j) + j] << endl;
			break;
		} else {
			um[temp] = i;
			rum[i] = temp;
		}
	}
	if (!flag) {
		cout << str << endl;
	}
	return 0;
}