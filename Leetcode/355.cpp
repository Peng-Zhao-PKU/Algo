typedef pair<int, int> pii;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        t = 0;
        f.clear();
        w.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        w[userId].push_back({t, tweetId});
        t++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto people = f[userId];
        people.insert(userId);
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (const auto& p : people) {
            for (const auto& tweet: w[p]) {
                if (pq.size() == 10) {
                    if (pq.top().first < tweet.first) {
                        pq.pop();
                        pq.push({tweet.first, tweet.second});
                    }
                } else {
                    pq.push({tweet.first, tweet.second});
                }
            }
        }
        
        vector<int> ret;
        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            ret.push_back(top.second);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
private:
    int t = 0;
    unordered_map<int, unordered_set<int>> f;
    unordered_map<int, vector<pii>> w;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */