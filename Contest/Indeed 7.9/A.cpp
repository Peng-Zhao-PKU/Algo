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
 
const int N = 1010;
const int inf = 0x0f0f0f0f;
 
void clear() {
 
}
 
int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    string s, t; cin >> s >> t;
 
    bool flag = false;
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
 
            string ss = s;
            string tt = t;
            for (int i = 0, n = s.size(); i < n; i++) {
                if (ss[i] == a) {
                    ss[i] = b;
                }
                if (tt[i] == a) {
                    tt[i] = b;
                }
            }
            if (ss == tt) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    cout << (flag ? "Possible" : "Impossible") << endl;
 
    return 0;
}