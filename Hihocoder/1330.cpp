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
typedef long long LL;

const int N = 110;
int nums[N], visit[N];
vector<LL> lcm;

LL gcd(LL a, LL b) {
    if (a < b) {
        swap(a, b);
    }
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    // freopen("input", "r", stdin);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        int index = nums[i] - 1;
        int ret = 1;
        while (index != i) {
            swap(nums[i], nums[index]);
            index = nums[i] - 1;
            ret++;
        }
        if (lcm.empty() || ret > 1) {
            lcm.push_back(ret);
        }
    }

    if (lcm.empty()) {
        while (1) cout << "Error" << endl;
    }
    LL ret = lcm[0];
    for (int i = 1, l = lcm.size(); i < l; i++) {
        LL current = gcd(ret, lcm[i]);
        ret = (ret * lcm[i]) / current;
    }
    cout << ret << endl;
	return 0;
}