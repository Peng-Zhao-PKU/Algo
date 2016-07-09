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
int n;
int matrix[N][N];
int visit[N];
int d[N];

void clear() {
    memset(matrix, 0, sizeof matrix);
    memset(visit, 0, sizeof visit);
    memset(d, inf, sizeof d);
}

int prim(int start = 0) {
    int ret = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[start] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int dis = front.first;
        int label = front.second;
        if (visit[label]) {
            continue;
        }
        visit[label] = 1;
        ret += dis;
        for (int i = 0; i < n; i++) {
            if (matrix[label][i] < d[i]) {
                d[i] = matrix[label][i];
                pq.push({matrix[label][i], i});
            }
        }
    }
    return ret;
}

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    cin >> n;
    clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << prim() << endl;
    return 0;
}