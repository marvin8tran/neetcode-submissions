class Twitter {
private:
    //we need a data structure for post order (heap)
    //data structure for connecting followers/users
    //hashmap lowkey
    unordered_map<int, unordered_set<int>> following;
    //userId, all following
    unordered_map<int, vector<pair<int, int>>> tweets;
    //userId (poster), tweetId, timestamp
    int timestamp;

    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second; // min heap by timestamp
        }
    };

   

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({tweetId, timestamp});
        following[userId].insert(userId);
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> minHeap;
        for(auto& x : following[userId]){
            for(auto& twt : tweets[x]){
                minHeap.push(twt);
                if(minHeap.size() > 10){
                    minHeap.pop();
                }
            }
        }
        vector<int> res(minHeap.size());
        int sz = minHeap.size() - 1;
        for(int i = sz; i >= 0; i--){
            res[i] = minHeap.top().first;
            minHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        following[followerId].insert(followerId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].erase(followeeId);
        }
        return;
    }
};
