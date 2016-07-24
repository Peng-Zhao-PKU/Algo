typedef long long LL;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = ((numerator ^ denominator) >> 31) & 1;
        LL num = abs((LL)numerator);
        LL denom = abs((LL)denominator);
        
        LL integers = num / denom;
        LL mod = num % denom;
        if (mod == 0) {
            if (integers == 0) {
                return "0";
            }
            return (sign ? "-" : "") + to_string(integers);
        }
        
        string ret = to_string(integers) + ".";
        unordered_map<LL, int> um;
        um[mod] = ret.size();
        while (mod) {
            mod *= 10;
            integers = mod / denom;
            mod %= denom;
            ret += to_string(integers);
            if (um.find(mod) == um.end()) {
                um[mod] = ret.size();
            } else {
                ret.insert(um[mod] + ret.begin(), '(');
                ret += ")";
                break;
            }
        }
        return (sign ? "-" : "") + ret;
    }
};