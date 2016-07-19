#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int MAXQ = 22;
const int MAXN = 10100;
const int inf = 0x0f0f0f0f;

map<int, int> label, rlabel;
int cnt = 0;
int dis[MAXQ][MAXN];
int visit[MAXN];
struct JOB {
    int L, S, E, T, C;
    bool operator<(const JOB& J) const {
        return C > J.C;
    }
} jobs[MAXQ];
vector<pii> edges[MAXN];
int done[MAXQ];
int ret = 0;
int MAXE = 0;
int N, M, Q;

void dijkstra(int start, int l) {
    memset(visit, 0, sizeof visit);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[l][start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int cost = pair.first;
        int location = pair.second;
        if (visit[location]) {
            continue;
        }
        visit[location] = 1;
        for (int i = 0; i < edges[location].size(); i++) {
            int to = edges[location][i].first;
            int weight = edges[location][i].second;
            if (dis[l][to] > dis[l][location] + weight) {
                dis[l][to] = dis[l][location] + weight;
                pq.push({dis[l][to], to});
            }
        }
    }
}

void dfs(int t, int location, int money) {
    ret = max(ret, money);
    if (t > MAXE) {
        return;
    }

    int l = label[location];
    int tempmoney = 0;
    for (int i = 0; i < Q; i++) {
        if (!done[i]) {
            int E = jobs[i].E;
            int L = jobs[i].L;
            if (t + dis[l][L] <= E) {
                tempmoney += jobs[i].C;
            }
        }
    }

    if (money + tempmoney <= ret) {
        return;
    }
    for (int i = 0; i < Q; i++) {
        if (!done[i]) {
            int S = jobs[i].S, E = jobs[i].E, L = jobs[i].L, T = jobs[i].T, C = jobs[i].C;
            if (t + dis[l][L] <= E) {
                int start = max(S, t + dis[l][L]);
                done[i] = 1;                
                dfs(start + T, L, money + C);
                done[i] = 0;
            }
        }
    }
}

void setLabel(int L) {
    if (label.find(L) == label.end()) {
        label[L] = cnt;
        rlabel[cnt] = L;
        cnt++;
    }
}

void clear() {
    memset(dis, inf, sizeof dis);
}

int main() {
    // freopen("input", "r", stdin);

    clear();
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int U, V, W; cin >> U >> V >> W;
        edges[U].push_back({V, W});
        edges[V].push_back({U, W});
    }

    setLabel(1);
    for (int i = 0; i < Q; i++) {
        int L, S, E, T, C; cin >> L >> S >> E >> T >> C;
        jobs[i] = {L, S, E, T, C};
        MAXE = max(MAXE, E);
        setLabel(L);
    }
    sort(jobs, jobs + Q);
    for (int i = 0; i < cnt; i++) {
        dijkstra(rlabel[i], i);
    }

    dfs(0, 1, 0);
    cout << ret << endl;
    return 0;
}