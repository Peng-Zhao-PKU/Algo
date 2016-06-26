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

const int N = 1010;
int zero[N], one[N];
char str[N];

int main() {
    // freopen("input", "r", stdin);
    int kase; cin >> kase;
    while (kase--) {
        memset(zero, 0, sizeof(zero));
        memset(one, 0, sizeof(one));
        memset(str, 0, sizeof(str));

        cin >> str;
        int n = strlen(str);
        one[0] = str[0] == '1';
        for (int i = 1; i < n; i++) {
            one[i] = one[i - 1] + (str[i] == '1');
        }
        zero[n - 1] = str[n - 1] == '0';
        for (int i = n - 2; i >= 0; i--) {
            zero[i] = zero[i + 1] + (str[i] == '0');
        }

        // for (int i = 0; i < n; i++) {
        //     cout << zero[i] << " " << one[i] << endl;
        // }

        int ret = one[n - 1];
        for (int i = 0; i < n; i++) {
            ret = min(ret, zero[i] + (i > 0 ? one[i - 1] : 0));
        }
        cout << ret << endl;
    }

    return 0;
}