#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> pii;

const int N = 100100;
const int SS = 100100;
const int X = 1001000;

pii direction = {0, 1}, head = {0, 0};
set<pii> food;
map<pii, int> snake;
int S, R, C;
int len = 1, pos = 0, t = 0;
struct Instruction {
    int time;
    char cmd;
    Instruction(): time(0), cmd(0) {}
    Instruction(int time_, char cmd_): time(time_), cmd(cmd_) {}
} instruction[SS];

void clear() {
    head = {0, 0};
    direction = {0, 1};
    food.clear();
    snake.clear();
    memset(instruction, 0, sizeof instruction);
    len = 1;
    pos = 0;
    t = 0;
}

void getDirection(char cmd) {
    // Right
    if (direction == make_pair(0, 1)) {
        if (cmd == 'R') {
            direction = {1, 0};
        } else {
            direction = {-1, 0};
        }
    } else if (direction == make_pair(0, -1)) {
        if (cmd == 'R') {
            direction = {-1, 0};
        } else {
            direction = {1, 0};
        }
    } else if (direction == make_pair(-1, 0)) {
        if (cmd == 'R') {
            direction = {0, 1};
        } else {
            direction = {0, -1};
        }
    } else {
        if (cmd == 'R') {
            direction = {0, -1};
        } else {
            direction = {0, 1};
        }
    }
}

bool move() {
    t++;
    // update head & direction
    int r = head.first;
    int c = head.second;
    
    // update instruction (pos)
    if (pos < S && t == instruction[pos].time) {
        getDirection(instruction[pos].cmd);
        pos++;
    }
    int rr = (r + direction.first + R) % R;
    int cc = (c + direction.second + C) % C;

    // update len, food
    if ((rr + cc) % 2) {
        if (food.find({rr, cc}) == food.end()) {
            food.insert({rr, cc});
            len++;
        }
    }

    // update snake
    if (snake.find({rr, cc}) != snake.end()) {
        int tt = snake[{rr, cc}];
        if (t - tt < len) {
            return false;
        }
    }
    snake[{rr, cc}] = t;
    head = {rr, cc};
    return true;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int testcase; scanf("%d", &testcase);
    for (int kase = 1; kase <= testcase; kase++) {
        clear();
        scanf("%d%d%d", &S, &R, &C);
        int maxx = 0;
        for (int i = 0; i < S; i++) {
            int time; char cmd;
            scanf("%d %c", &time, &cmd);
            ++time;
            instruction[i] = Instruction(time, cmd);
            maxx = max(maxx, time);
        }

        bool live = true;
        while ((live = move()) && t < maxx) ;
        if (live) {
            pii current = head;
            while ((live = move()) && head != current) ;
        }
        cout << "Case #" << kase << ": " << len << endl;
    }
}
