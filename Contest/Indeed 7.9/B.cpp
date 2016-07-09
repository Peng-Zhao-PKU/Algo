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
    int a, b, k; cin >> a >> b >> k;
    k += 2;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 0});
    pq.push({0.5, 1});
    while (k > 1) {
        auto front = pq.top();
        pq.pop();
        double t = front.first;
        int l = front.second;
        // cout << t << " " << (l == 0 ? "Takahashi" : "Aoki") << endl;
        if (l == 0) {
            pq.push({t + a, l});
        } else {
            pq.push({t + b, l});
        }
        k--;
    }
    int l = pq.top().second;
    cout << (l == 0 ? "Takahashi" : "Aoki") << endl;
 
    return 0;
}