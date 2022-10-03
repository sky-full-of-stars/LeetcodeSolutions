class Solution
{
private:
    int min(int a, int b)
    {
        return (a<=b)? a:b;
    }
    int ways(vector<int> &coins, int total, vector<int> &dp)
    {
        if(dp[total] != -1)
            return dp[total];
        
        if(total == 0)
            return dp[0] = 0;
        
        int long ans = INT_MAX; // impossible to achieve
        for(int cur: coins)
        {
            if(cur <= total)
            {
                int subResult = ways(coins, total-cur, dp);
                
                if(subResult != INT_MAX) // if possible to achieve, then update answer
                {
                    ans = min(ans, 1+ subResult);
                }
            }
            else
            {
                break;
            }
        }
        return dp[total]= ans;
    }
    
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, -1);
        
        int ans = ways(coins, amount, dp);
        return (ans == INT_MAX) ? -1: ans;
    }
};