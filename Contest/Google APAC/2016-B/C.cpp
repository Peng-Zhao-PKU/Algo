#include <bits/stdc++.h>
 
using namespace std;

typedef long long LL;
typedef unsigned int UI;
const LL N = (LL)(1e15) + 10;
const int P = (int)(4e7) + 10;

set<LL> primes;
map<LL, int> memorize;
vector<LL> factors;
int prime[P];

void init() {
    for (LL i = 2; i < P; i++) {
        if (prime[i]) continue;
        for (LL j = i * i; j < P; j += i) {
            prime[j] = true;
        }
    }
    for (LL i = 2; i < P; i++) {
        if (!prime[i]) {
            primes.insert(i);
        }
    }
}

void clear() {
    memorize.clear();
    factors.clear();
}

LL digits(LL n) {
    LL ret = 0;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

bool isPrimeOr1(LL n) {
    return n == 1 || primes.find(n) != primes.end();
}

LL removeFactor(LL n, LL factor) {
    while (n % factor == 0) {
        n /= factor;
    }
    return n;
}

void getFactors(LL n) {
    for (const LL&i : primes) {
        if (n % i == 0) {
            factors.push_back(i);
            n = removeFactor(n, i);
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
}

bool dfs(LL n) {
    if (memorize.find(n) != memorize.end()) {
        return memorize[n];
    }
    LL sum = digits(n);
    if (isPrimeOr1(sum)) {
        return memorize[n] = false;
    }
    for (const LL& i : factors) {
        if (n % i == 0) {
            LL nn = removeFactor(n, i);
            if (!dfs(nn)) {
                return memorize[n] = true;
            }
        }
    }
    return memorize[n] = false;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    init();

    int testcase; cin >> testcase;
    for (int kase = 1; kase <= testcase; kase++) {
        clear();
        LL n; cin >> n;
        getFactors(n);
        cout << "Case #" << kase << ": " << (dfs(n) ? "Laurence" : "Seymour") << endl;
    }
    return 0;
}