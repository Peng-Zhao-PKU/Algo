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

const int N = 100100;
char str[N], ret[N];
int cnt[256];

bool isValid(char begin, int len) {
    int maxv = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        maxv = max(maxv, cnt[c]);
    }
    if (cnt[begin] == maxv) {
        return maxv <= len / 2;
    } else {
        return maxv <= (len + 1) / 2;
    }
}

int main() {
    // freopen("input", "r", stdin);
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        cnt[str[i]]++;
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        bool current = false;
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c] > 0 && (i == 0 || c != ret[i - 1])) {
                cnt[c]--;
                if (isValid(c, n - 1 - i)) {
                    ret[i] = c;
                    current = true;
                    break;
                } else {
                    cnt[c]++;
                }
            }
        }
        if (!current) {
            cout << "INVALID" << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << ret << endl;
    }
	return 0;
}