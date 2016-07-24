
typedef pair<string, string> pss;

class Solution {
public:
    vector<string> findItinerary(vector<pss> tickets) {
        unordered_map<string, vector<string>> edges;
        vector<string> ret;
        
        for (const auto& pair: tickets) {
            edges[pair.first].push_back(pair.second);
        }
        for (const auto& pair: edges) {
        	vector<string> v = pair.second;
        	sort(v.begin(), v.end());
        	edges[pair.first] = v;
        }
        dfs(0, "JFK", tickets.size(), edges, ret);
        return ret;
    }
    
    bool dfs(int cur, string now, int target, unordered_map<string, vector<string>>& edges, vector<string>& ret) {
        ret.push_back(now);
        if (cur >= target) {
            return true;
        }
        for (int i = 0; i < edges[now].size(); i++) {
            if (edges[now][i].empty()) continue;
            string temp = edges[now][i];
            edges[now][i] = "";
            if (dfs(cur + 1, temp, target, edges, ret)) {
                return true;
            }
            edges[now][i] = temp;
        }
        ret.pop_back();
        return false;
    }
};