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
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
	bool operator < (const Interval& interval) const {
        return (start < interval.start);
    }
} A[N], B[N];

int merge(Interval* interval, int n) {
	if (n <= 0) {
		return 0;
	}

	int idx = 0;
	sort(interval, interval + n);

	Interval current = interval[0];
	for (int i = 0; i < n; i++) {
		if (interval[i].start > current.end) {
			interval[idx++] = current;
			current = interval[i];
		} else {
			current.end = max(current.end, interval[i].end);
		}
	}
	interval[idx++] = current;
	return idx;
}

int diff(Interval* A, Interval* B, int n, int m) {
	if (n <= 0 || m <= 0) {
		return 0;
	}

	int ret = 0, i = 0, j = 0;
	while (i < n && j < m) {
		if (A[i].end <= B[j].start) {
			ret += A[i].end - A[i].start;
			i++;
		} else if (A[i].start >= B[j].end) {
			j++;
		} else if (B[j].end >= A[i].end) {
			int len = A[i].end - B[j].start;
			ret += max(0, A[i].end - A[i].start - len);
			i++;
		} else {
			int len = B[j].end - B[j].start;
			ret += max(0, B[j].end - A[i].start - len);
			A[i].start = B[j].end;
			j++;
		}
	}
	while (i < n) {
		ret += A[i].end - A[i].start;
		i++;
	}
	return ret;
}

int main() {
	// freopen("input", "r", stdin);
	int n, m; scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		int start, end; scanf("%d%d", &start, &end);
		A[i].start = start, A[i].end = end;
	}

	for (int i = 0; i < m; i++) {
		int start, end; scanf("%d%d", &start, &end);
		B[i].start = start, B[i].end = end;
	}

	n = merge(A, n);
	m = merge(B, m);
	printf("%d\n", diff(A, B, n, m));
	return 0;
}