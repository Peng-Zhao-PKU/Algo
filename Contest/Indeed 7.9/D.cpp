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
typedef long long LL;

const int N = 300300;
const int inf = 0x0f0f0f0f;
char str[N];
LL A[N];

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int n; cin >> n;
    scanf("%s", str);
    for (int i = 0; i < n + 1; i++) {
        scanf("%lld", A + i);
    }
    int last = 0, open = 0;
    LL minv = A[0], ret = 0;

    for (int i = 0; i < n; i++) {
        minv = min(minv, A[i]);
        if (str[i] == '(') {
            open++;
        } else if (--open < 0) {
            last = i + 1;
            ret += minv;
            open = 0;
        }
    }
    if (open > 0) {
        minv = A[n];
        open = 0;
        for (int i = n - 1; i >= last; i--) {
            if (str[i] == ')') {
                open++;
            } else if (--open < 0) {
                ret += minv;
                open = 0;
            }
            minv = min(minv, A[i]);
        }
    }
    cout << ret << endl;
    return 0;
}