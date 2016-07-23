class Solution {
public:

    string scale[4] = {"", "Thousand", "Million", "Billion"};
    string below20[21] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                      "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                      "Nineteen", "Twenty"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    void getLessThan1000(int num, vector<string>& ret) {
        int hundred = num / 100;
        if (hundred) {
            ret.push_back(below20[hundred]);
            ret.push_back("Hundred");
        }
        num = num % 100;
        if (num <= 20) {
            ret.push_back(below20[num]);
        } else {
            ret.push_back(tens[num / 10]);
            ret.push_back(below20[num % 10]);
        }
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        vector<string> ret;
        int base = 0;
        int temp = num;
        while (temp / 1000) {
            base++;
            temp /= 1000;
        }

        while (base >= 0) {
            int current = (num / (int)pow(1000, base)) % 1000;
            if (current) {
                getLessThan1000(current, ret);
                ret.push_back(scale[base]);
            }
            base--;
        }
        string res = "";
        for (const string& str: ret) {
            if (str.empty()) continue;
            if (res.empty()) {
                res += str;
            } else {
                res += " " + str;
            }
        }
        return res;
    }
};