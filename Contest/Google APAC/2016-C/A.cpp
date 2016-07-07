#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 110;

int P[N];
int p, n, m, cnt = 0;;
map<string, int> label;

struct Athletes {
    string name;
    vector<int> scores;
    int totalScore = 0;

    void calcTotal(int m) {
        int ret = 0;
        sort(scores.begin(), scores.end(), greater<int>());
        for (int i = 0; i < min((int)scores.size(), m); i++) {
            ret += scores[i];
        }
        totalScore = ret;
    }
};

vector<Athletes> athletes;

void clear() {
    memset(P, 0, sizeof(P));
    label.clear();
    athletes.clear();
    cnt = 0;
}

int getLabel(string& name) {
    if (label.find(name) != label.end()) {
        return label[name];
    }
    return label[name] = cnt++;
}

void addScore(int index, string& name, int score) {
    if (index == athletes.size()) {
        Athletes a = Athletes();
        a.scores.push_back(score);
        a.name = name;
        athletes.push_back(a);
    } else {
        athletes[index].scores.push_back(score);
    }
}

struct compare {
    bool operator() (const Athletes& a, const Athletes &b) const {
        if (a.totalScore != b.totalScore) {
            return a.totalScore > b.totalScore;
        }
        return a.name < b.name;
    }
};

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int kase; cin >> kase;
    for (int t = 1; t <= kase; t++) {
        clear();
        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> P[i];
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int w; cin >> w;
            for (int j = 0; j < p; j++) {
                string name; cin >> name;
                addScore(getLabel(name), name, P[j] * w);
            }
        }
        cin >> m;
        for (int i = 0; i < athletes.size(); i++) {
            athletes[i].calcTotal(m);
        }
        sort(athletes.begin(), athletes.end(), compare());

        cout << "Case #" << t << ":" << endl;
        for (int i = 0, rank = 1, l = athletes.size(); i < l; i++) {
            if (i > 0 && athletes[i].totalScore < athletes[i - 1].totalScore) {
                rank = i + 1;
            }
            cout << rank << ": " << athletes[i].name << endl;
        }
    }

    return 0;
}
