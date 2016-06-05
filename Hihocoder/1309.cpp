#include <cmath>
#include <cstdio>
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

const int N = 100100;
struct Interval {
	int start, end;
	bool operator< (const Interval& a) const {
		return end > a.end;
	}
} interval[N];

priority_queue<Interval> pq;
bool compare(const Interval &a, const Interval &b) {
	return a.start < b.start;
}

int main() {
	// freopen("input", "r", stdin);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end; cin >> start >> end;
		interval[i].start = start;
		interval[i].end = end;
	}
	sort(interval, interval + n, compare);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (!pq.empty() && pq.top().end <= interval[i].start) {
			Interval top = pq.top();
			pq.pop();
			top.end = interval[i].end;
			pq.push(top);
		} else {
			ret++;
			pq.push(interval[i]);
		}
	}
	cout << ret << endl;
	return 0;
}