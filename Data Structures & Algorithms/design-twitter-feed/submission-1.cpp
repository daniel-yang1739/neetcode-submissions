class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> userFollow;
public:
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_map<int, int> userTweetIdx;
        priority_queue<pair<int, int>> maxHeap;
        if (userTweets.count(userId)) {
            userTweetIdx[userId] = userTweets[userId].size() - 1;
            maxHeap.push({userTweets[userId].back().first, userId});
        }
        for (const auto& followeeId : userFollow[userId]) {
            if (userTweets.count(followeeId)) {
                userTweetIdx[followeeId] = userTweets[followeeId].size() - 1;
                maxHeap.push({userTweets[followeeId].back().first, followeeId});
            }
        }
        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            const auto [timestamp, uid] = maxHeap.top();
            maxHeap.pop();
            int tweetId = userTweets[uid][userTweetIdx[uid]].second;
            res.push_back(tweetId);
            --userTweetIdx[uid];
            if (userTweetIdx[uid] >= 0) {
                maxHeap.push(
                    {userTweets[uid][userTweetIdx[uid]].first, uid});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            userFollow[followerId].insert(followeeId);
        } 
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userFollow[followerId].count(followeeId)) {
            userFollow[followerId].erase(followeeId);
        }
    }
};
