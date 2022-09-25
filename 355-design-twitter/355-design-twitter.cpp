class Twitter 
{
    
public:
    int curTime;
    
    map<int, set<int>> followers;
    map<int, vector< pair<int,int> > > tweets;
    Twitter() 
    {
        curTime = INT_MAX;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_back({curTime--,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>> mxHeap;
        
        for(int follower : followers[userId])
        {
           vector<pair<int,int>> allTweets = tweets[follower];
           for(pair<int,int> tweet : allTweets)
           {
               mxHeap.push({tweet.first, tweet.second});
               if(mxHeap.size() > 10)
                   mxHeap.pop();
           }
        }
        
           vector<pair<int,int>> allTweets = tweets[userId];
           for(pair<int,int> tweet : allTweets)
           {
               mxHeap.push({tweet.first, tweet.second});
               if(mxHeap.size() > 10)
                   mxHeap.pop();
           }
        
        
        
        while(!mxHeap.empty())
        {
            ans.push_back(mxHeap.top().second);
            mxHeap.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) 
    {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        auto pos = find(followers[followerId].begin(), followers[followerId].end(), followeeId);
        if(pos != followers[followerId].end())
            followers[followerId].erase(pos);
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