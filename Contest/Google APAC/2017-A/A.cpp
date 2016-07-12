#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
 
using namespace std;

const int N = 110;
const int M = 30;
typedef long long LL;
typedef unsigned int UI;

char str[N][M];
int cnt[N];

void clear() {
    memset(str, 0, sizeof(str));
    memset(cnt, 0, sizeof(cnt));
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int testcase; cin >> testcase;
    for (int kase = 1; kase <= testcase; kase++) {
        int n; cin >> n;
        cin.get();
        for (int i = 0; i < n; i++) {
            cin.getline(str[i], M, '\n');
            set<char> s;
            for (int j = 0; str[i][j]; j++) {
                if (str[i][j] == ' ') continue;
                s.insert(str[i][j]);
            }
            cnt[i] = s.size();
        }

        int ret = 0;
        int maxv = cnt[0];
        for (int i = 1; i < n; i++) {
            if (cnt[i] > maxv || (cnt[i] == maxv && strcmp(str[i], str[ret]) < 0)) {
                maxv = cnt[i];
                ret = i;
            }
        }
        cout << "Case #" << kase << ": " << str[ret] << endl;
    }
    return 0;
}