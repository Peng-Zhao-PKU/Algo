#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int N = 10000;
char str[N];

int main() {
    // freopen("input", "r", stdin);
    bool space = false, capital = true;
    bool seperate = true;
    int j = 0;
    cin.getline(str, N, 0);
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (!space && capital) {
            if (ch == ' ') {
                if (!seperate) {
                    space = true;
                }
            } else if (ch == '\n') {
                str[j++] = '\n';
                seperate = true;
            } else {
                // only letters
                str[j++] = toupper(ch);
                capital = false;
            }
        } else if (!space && !capital) {
            if (ch == ' ') {
                space = true;
            } else if (ch == '.') {
                str[j++] = ch;
                seperate = false;
                capital = true;
            } else {
                str[j++] = ch;
            }
        } else if (space && capital) {
            if (ch == ' ') {
                continue;
            } else if (ch == '\n') {
                str[j++] = ch;
                seperate = true;
                space = false;
            } else {
                // only letters
                str[j++] = ' ';
                str[j++] = toupper(ch);
                space = false;
                capital = false;
            }
        } else if (space && !capital) {
            if (ch == ' ') {
                continue;
            } else if (ch == '.') {
                str[j++] = ch;
                seperate = false;
                capital = true;
                space = false;
            } else if (ch == ',') {
                str[j++] = ch;
                space = false;
            } else {
                str[j++] = ' ';
                str[j++] = ch;
                space = false;
            }
        }
    }
    str[j] = 0;
    cout << str << endl;
}