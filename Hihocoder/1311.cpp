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
string str;

int mutipleBy2(int len) {
	int carry = 0;
	for (int i = len - 1; i >= 0; i--) {
		int current = str[i] - '0';
		int sum = current * 2 + carry;
		str[i] = (sum % 10) + '0';
		carry = sum / 10;
	}
	return carry;
}

int main() {
	// freopen("input", "r", stdin);
	int kase; cin >> kase;
	while (kase--) {
		cin >> str;
		bool flag = true;
		str = str.substr(2, str.size() - 2);
		int len = str.size();
		string ret = "";

		if (str == "0") {
			cout << "0.0" << endl;
			continue;
		}

		while (len) {
			if (str[len - 1] != '5') {
				flag = false;
				break;
			}
			int carry = mutipleBy2(len);
			ret = ret + (char)('0' + carry);
			len--;
		}
		if (flag) {
			cout << "0." << ret << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}