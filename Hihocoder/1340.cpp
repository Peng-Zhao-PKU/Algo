#include <bits/stdc++.h>
 
using namespace std;

typedef long long LL;
typedef unsigned int UI;
const int N = 1010;
int Robot[3];

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    cin >> Robot[0] >> Robot[1] >> Robot[2];
    sort(Robot, Robot + 3);
    int ret = 0;
    while (Robot[2] > 0) {
        int transport = 0;
        vector<int> v;
        for (int i = 0; i <= Robot[0]; i++) {
            if (i > 20) break;
            for (int j = 0; j <= Robot[1]; j++) {
                if (i + j > 20) break;
                for (int k = 0; k <= Robot[2]; k++) {
                    int sum = i + j + k;
                    if (sum > 20) break;
                    if (sum > 15 && max(i, max(j, k)) * 2 > sum) continue;
                    if (sum > transport) {
                        transport = sum;
                        v = {i, j, k};
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            Robot[i] -= v[i];
        }
        sort(Robot, Robot + 3);
        ret++;
    }
    cout << ret * 6 << endl;
    return 0;
}