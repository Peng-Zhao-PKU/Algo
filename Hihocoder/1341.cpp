#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int N = 22;

string str[N];
vector<int> lop[N];
int visit[256];
map<char, int> m;

bool isLetter(string& str) {
	return str.size() == 1 && (str[0] >= 'A' && str[0] <= 'Z');
}

int getNum(string& str) {
	if (isLetter(str)) {
		return m[str[0]];
	}
	return stoi(str);
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < str[i].size(); ) {
			int next = min(str[i].find_first_of("<", j), str[i].size());
			if (next < str[i].size()) {
				lop[i].push_back(next);
			}
			j = next + 1;
		}
	}
}

bool check(int k) {
	// first number
	string sub = str[k].substr(0, lop[k][0]);
	int num = getNum(sub);
	for (int i = 0, l = lop[k].size(); i < l; i++) {
		int start = lop[k][i] + 1;
		if (str[k][start] == '=') {
			start++;
		}
		int nextPos = i + 1 < l ? lop[k][i + 1] : str[k].size();
		sub = str[k].substr(start, nextPos - start);
		int current = getNum(sub);

		if (str[k][lop[k][i] + 1] == '=') {
			if (num > current) {
				return false;
			}
		} else {
			if (num >= current) {
				return false;
			}
		}
		num = current;
	}
	return true;
}

int main() {
    // freopen("input", "r", stdin);
    int n; cin >> n;
    int var = 0;
    for (int i = 0; i < n; i++) {
    	cin >> str[i];
    	for (int j = 0; j < str[i].size(); j++) {
    		char ch = str[i][j];
	    	if (ch >= 'A' && ch <= 'Z') {
	    		if (visit[ch] == 0) {
	    			visit[ch] = 1;
	    			var++;
	    		}
	    	}
    	}
    }

    init(n);

    int t; cin >> t;
    while (t--) {
    	m.clear();
    	for (int i = 0; i < var; i++) {
    		char ch; int num;
    		cin >> ch >> num;
    		m[ch] = num;
    	}
    	bool flag = true;
    	for (int i = 0; i < n; i++) {
    		if (!(flag = check(i))) {
    			break;
    		}
    	}
    	cout << (flag ? "Yes": "No") << endl;
    }
    return 0;
}