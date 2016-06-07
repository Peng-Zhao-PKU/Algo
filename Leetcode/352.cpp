/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int val) {
        int start = val, end = val;
        auto it = s.lower_bound(Interval(val, val));
        if (it != s.begin() && (--it)->end + 1 < val) {
            ++it;
        }
        while (it != s.end() && it->start - 1 <= val && it->end + 1 >= val) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = s.erase(it);
        }
        s.insert(Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval> (s.begin(), s.end());
    }

private:
    struct Cmp {
        bool operator() (const Interval& a, const Interval &b) {
            return a.start < b.start;
        }
    };
    set<Interval, Cmp> s;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */