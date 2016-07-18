#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
const int N = 2020;

struct Node {
    LL a, b;
    Node(LL a_, LL b_) {
        LL gcd = __gcd(a_, b_);
        a = a_ / gcd;
        b = b_ / gcd;
    }
    bool operator<(const Node& node) const {
        return a * node.b < b * node.a;
    }
    bool operator==(const Node& node) const {
        return a * node.b == b * node.a;
    }
};

set<Node> s;
LL A[N], B[N], C[N];

void clear() {
    s.clear();
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int testcase = 1; testcase <= kase; testcase++) {
        clear();
        int NP, NE, NT; cin >> NP >> NE >> NT;
        for (int i = 0; i < NP; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < NE; i++) {
            cin >> B[i];
        }
        for (int i = 0; i < NT; i++) {
            cin >> C[i];
        }
        for (int i = 0; i < NE; i++) {
            for (int j = 0; j < NE; j++) {
                if (i == j) continue;
                s.insert(Node(B[i], B[j]));
            }
        }
        int M; cin >> M;
        cout << "Case #" << testcase << ":" << endl;
        for (int i = 0; i < M; i++) {
            LL P, Q; cin >> P >> Q;
            bool flag = false;
            for (int j = 0; j < NP; j++) {
                for (int k = 0; k < NT; k++) {
                    if (s.find(Node(P * C[k], Q * A[j])) != s.end()) {
                        flag = true;
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
    return 0;
}