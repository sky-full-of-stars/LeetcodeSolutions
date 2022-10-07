class Solution 
{
private:
    int ways(int sum, int curIdx, vector<int> & coins, map<pair<int,int>, int> &dp)
    {
        if(dp.find({sum, curIdx}) != dp.end())
           return dp[{sum, curIdx}];
        
        if(sum == 0)
            return dp[{sum, curIdx}] = 1;
        if(curIdx == coins.size())
            return dp[{sum, curIdx}] = 0;
        
        int select = 0, nonSelect = 0;
        if(coins[curIdx] <= sum)
            select = ways(sum - coins[curIdx], curIdx, coins, dp);
        
        nonSelect = ways(sum, curIdx+1, coins, dp);
        
        return dp[{sum, curIdx}] = select + nonSelect;
    }
public:
    int ans = 0;
    map<pair<int,int>, int> dp;
    int change(int amount, vector<int>& coins) 
    {
        return ways(amount, 0, coins, dp);
    }
};