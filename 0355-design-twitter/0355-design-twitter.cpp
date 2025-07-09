class Twitter {
private:
    struct Tweet{
        int tweetID;
        int time;
        Tweet* next;

        Tweet(int time, int tweetID) : time(time), tweetID(tweetID), next(NULL){}
    };

    class User{
    public:
        int userID;
        unordered_set<int> followed;
        Tweet* tweetHead;

        User(int userID){
            this->userID = userID;
            follow(userID); //user always follow themselves
            tweetHead = NULL;
        }

        void follow(int id){
            followed.insert(id);
        }

        void unfollow(int id){
            if (id != userID){
                followed.erase(id);
            }
        }

        void post(int time, int id){
            // We store the new tweet to the start of the of tweet LL
            Tweet* new_tweet = new Tweet(time, id);
            new_tweet->next = tweetHead;
            tweetHead = new_tweet;
        }
    };

    unordered_map<int, User*> userMap;
    int time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->post(time++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (userMap.find(userId) == userMap.end()) return res;

        struct HeapNode {
            Tweet* tweet;
            bool operator<(const HeapNode& other) const {
                return tweet->time < other.tweet->time; // max heap
            }
        };

        priority_queue<HeapNode> pq;

        for (int uid : userMap[userId]->followed) {
            if (userMap.find(uid) == userMap.end()) continue;
            Tweet* tweet = userMap[uid]->tweetHead;
            if (tweet) {
                pq.push(HeapNode{tweet});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            Tweet* tweet = pq.top().tweet;
            pq.pop();
            res.push_back(tweet->tweetID);
            if (tweet->next) {
                pq.push(HeapNode{tweet->next});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }
        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }
        userMap[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) != userMap.end()) {
            userMap[followerId]->unfollow(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */