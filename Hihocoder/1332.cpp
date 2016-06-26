#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:

    stack<string> s;
    stack<int> rpe;
    
    int calculate(string str) {
        const int n = str.size();
        
        for (int i = 0; i < n; ) {
            int op = min(str.find_first_of("+-*/()", i), str.size());
            string token = str.substr(i, max(op - i, 1));

            if (isOperand(token)) {
                switch (token[0]) {
                    case '(':
                        s.push(token);
                        break;
                    case '+':
                    case '-':
                    case ')':
                        while (!s.empty() && s.top() != "(") {
                            cal(s.top());
                            s.pop();
                        }
                        if (!s.empty() && s.top() == "(" && token == ")") {
                            s.pop();
                        } else {
                            s.push(token);
                        }
                        break;
                    case '*':
                    case '/':
                        while (!s.empty() && (s.top() == "*" || s.top() == "/")) {
                            cal(s.top());
                            s.pop();
                        }
                        s.push(token);
                        break;
                }
                i++;
            } else {
                rpe.push(stoi(token));
                i = op;
            }
        }
        while (!s.empty()) {
            cal(s.top());
            s.pop();
        }
        return rpe.top();
    }
    
    bool isOperand(const string& str) {
        return str.find_first_of("+-*/()") != string::npos;
    }
    
    void cal(const string & str) {
        int second = rpe.top(); rpe.pop();
        int first = rpe.top(); rpe.pop();
        switch (str[0]) {
            case '+':
                rpe.push(first + second);
                break;
            case '-':
                rpe.push(first - second);
                break;
            case '*':
                rpe.push(first * second);
                break;
            case '/':
                rpe.push(first / second);
                break;
        }
    }
};

int main() {
    // freopen("input", "r", stdin);
    string str; cin >> str;
    Solution s;
    cout << s.calculate(str) << endl;
	return 0;
}