typedef pair<int, int> pii;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (um.find(key) == um.end()) {
            return -1;
        }
        auto it = um[key];
        int value = it->second;
        l.erase(it);
        l.push_back({key, value});
        um[key] = --l.end();
        return value;
    }
    
    void set(int key, int value) {
        if (um.find(key) == um.end()) {
            if (l.size() < capacity) {
                l.push_back({key, value});
                um[key] = --l.end();
            } else {
                auto it = l.front();
                int k = it.first;
                l.erase(l.begin());
                um.erase(k);
                l.push_back({key, value});
                um[key] = --l.end();
            }
        } else {
            auto it = um[key];
            l.erase(it);
            l.push_back({key, value});
            um[key] = --l.end();
        }
    }
private:
    int capacity;
    list<pii> l;
    unordered_map<int, list<pii>::iterator> um;
};