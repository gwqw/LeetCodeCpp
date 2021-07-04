/**
    355. Design Twitter
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:
- Twitter() Initializes your twitter object.
- void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
- List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
- void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
- void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

Example 1:
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

Constraints:
1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 10^4
All the tweets have unique IDs.
At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and unfollow.

Algo: getNewsFeed: merge k-sorted lists
*/

struct Tweet {
    int tweet_id = 0;
    int timestamp = 0;
    unique_ptr<Tweet> next;
    
    Tweet(int tweet_id_, int timestamp_, unique_ptr<Tweet> next_) 
        : tweet_id(tweet_id_), timestamp(timestamp_), next(move(next_))
    {}
    
    friend bool operator<(const Tweet& lhs, const Tweet& rhs) {
        return lhs.timestamp < rhs.timestamp;
    }
};

struct TweetPtrCompare {
    bool operator()(Tweet* lhs, Tweet* rhs) const {
        return *lhs < *rhs;
    }    
};

struct User {
    unique_ptr<Tweet> posts_head; // or list?
    unordered_set<User*> follow_users;
    
    void postTweet(int tweetId, int timestamp) {
        auto head = make_unique<Tweet>(tweetId, timestamp, move(posts_head));
        posts_head = move(head);
    }
    
    void follow(User* user) {
        follow_users.insert(user);
    }
    
    void unfollow(User* user) {
        follow_users.erase(user);
    }
    
    vector<int> getNews() {
        priority_queue<Tweet*, vector<Tweet*>, TweetPtrCompare> pq(TweetPtrCompare{});
        if (posts_head) pq.push(posts_head.get());
        for (auto user : follow_users) {
            if (user->posts_head) {
                pq.push(user->posts_head.get());
            }
        }
        
        vector<int> res;
        res.reserve(10);
        while (res.size() < 10 && !pq.empty()) {
            auto head = pq.top();
            pq.pop();
            res.push_back(head->tweet_id);
            head = head->next.get();
            if (head) pq.push(head);
        }
        return res;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].postTweet(tweetId, timestamp++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        return users[userId].getNews();
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].follow(&users[followeeId]);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].unfollow(&users[followeeId]);
    }
    
private:
    unordered_map<int, User> users;
    int timestamp = 0;
};

// with vector

struct Tweet {
    int tweet_id = 0;
    int timestamp = 0;
    
    Tweet(int tweet_id_, int timestamp_, unique_ptr<Tweet> next_) 
        : tweet_id(tweet_id_), timestamp(timestamp_)
    {}
    
    friend bool operator<(const Tweet& lhs, const Tweet& rhs) {
        return lhs.timestamp < rhs.timestamp;
    }
};

struct TweetIteratorCmp {
    bool operator()(deque<Tweet>::const_iterator lhs, deque<Tweet>::const_iterator rhs) {
        return *lhs < *rhs;
    }
};

struct User {
    User(const unordered_map<int, User>& users_)
        : users(users_)
    {}
    
    const unordered_map<int, User>& users;
    deque<Tweet> posts;
    unordered_set<int> follow_users;
    
    void postTweet(int tweetId, int timestamp) {
        posts.emplace_front(tweetId, timestamp);
    }
    
    void follow(int user) {
        follow_users.insert(user);
    }
    
    void unfollow(int user) {
        follow_users.erase(user);
    }
    
    vector<int> getNews() {
        priority_queue<deque<Tweet>::const_iterator, vector<deque<Tweet>::const_iterator>, TweetIteratorCmp> pq(TweetIteratorCmp{});
        if (!posts.empty()) pq.push(posts.begin());
        for (auto user : follow_users) {
            const auto& p = users.at(user).posts;
            if (!p) pq.push(p.begin());
        }
        
        vector<int> res;
        res.reserve(10);
        while (res.size() < 10 && !pq.empty()) {
            auto post_iter = pq.top();
            pq.pop();
            res.push_back(post_iter->tweet_id);
            ++post_iter;
            if (post_iter != cont.end() make IteratorRange) pq.push(post_iter);
        }
        return res;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].postTweet(tweetId, timestamp++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        return users[userId].getNews();
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].follow(&users[followeeId]);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].unfollow(&users[followeeId]);
    }
    
private:
    unordered_map<int, User> users;
    int timestamp = 0;
};



/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

