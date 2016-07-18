#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

struct CHUNK {
    int start, end, label;
    CHUNK(int start_, int end_, int label_) {
        start = start_;
        end = end_;
        label = label_;

    }
    bool operator< (const CHUNK& c) const {
        return label < c.label;
    }
};
map<int, int> interval; // key -> start, value -> end

map<int, int>::iterator enough(int len) {
    for (auto it = interval.begin(); it != interval.end(); ++it) {
        if (it->second - it->first + 1 >= len) {
            return it;
        }
    }
    return interval.end();
}

void insert(map<int, int>::iterator it, int len, int label, vector<CHUNK>& chunk) {
    int start = it->first;
    int end = it->second;
    interval.erase(it);
    if (start + len <= end) {
        interval.insert({start + len, end});
    }
    chunk.push_back(CHUNK(start, start + len - 1, label));
}

void merge(int start, int end) {
    auto it = interval.lower_bound(start);
    int nstart = start;
    int nend = end;
    if (it != interval.begin() && (--it)->second + 1 < start) ++it;
    while (it != interval.end()) {
        if (it->second + 1 >= start && it->first - 1 <= end) {
            nstart = min(nstart, it->first);
            nend = max(nend, it->second);
            it = interval.erase(it);
        } else break;
    }

    interval.insert({nstart, nend});
}

int main() {
    // freopen("input", "r", stdin);

    int n, m, pos = 0; cin >> n >> m;
    vector<CHUNK> chunk;
    interval.insert({0, m - 1});
    for (int i = 0; i < n; i++) {
        map<int, int>::iterator it;
        int len; cin >> len;
        while ((it = enough(len)) == interval.end()) {
            merge(chunk[pos].start, chunk[pos].end);
            pos++;
        }
        insert(it, len, i + 1, chunk);
    }
    sort(chunk.begin() + pos, chunk.end());
    for (int i = pos; i < chunk.size(); i++) {
        cout << chunk[i].label << " " << chunk[i].start << endl;
    }
}