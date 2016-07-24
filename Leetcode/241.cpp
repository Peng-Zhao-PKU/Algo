
class Solution {
public:
    vector<int> diffWaysToCompute(string& str) {
        return diffWaysToCompute(str, 0, str.size());
    }

    vector<int> diffWaysToCompute(string input, int start, int end) {
        string sub = input.substr(start, end - start);
        if (sub.find_first_of("+-*") == string::npos) {
            return {stoi(sub)};
        }
        vector<int> ret;
        for (int i = start; i < end; i++) {
            if (isOp(input[i])) {
                vector<int> left = diffWaysToCompute(input, start, i);
                vector<int> right = diffWaysToCompute(input, i + 1, end);
                for (const int& l : left) {
                    for (const int& r : right) {
                        ret.push_back(compute(l, r, input[i]));
                    }
                }
            }
        }
        return ret;
    }
private:
    bool isOp(char c) {
        return c == '+' || c == '-' || c == '*';
    }
    int compute(int l, int r, char op) {
        if (op == '+') {
            return l + r;
        } else if (op == '-') {
            return l - r;
        }
        return l * r;
    }
};