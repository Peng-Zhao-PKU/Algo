class Solution {
public:
    bool isValidSerialization(string preorder) {
        int dep = 0;
        for (int i = 0; i < preorder.size(); ) {
            int j = min(preorder.find_first_of(",", i + 1), preorder.size());
            string sub = preorder.substr(i, j - i);
            if (sub == "#") {
                if (--dep < 0 && j < preorder.size()) {
                    return false;
                }
            } else {
                dep++;
            }
            i = j + 1;
        }
        return dep == -1;
    }
};