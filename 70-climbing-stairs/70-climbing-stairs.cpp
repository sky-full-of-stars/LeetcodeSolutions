class Solution 
{
private:
    int solve(int n, vector<int> &dp)
    {
        if(dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n-1, dp) + solve(n-2, dp); 
    } 
    
public:
    int climbStairs(int n) 
    {
        if(n<=3)
            return n;
        
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        return solve(n, dp);       
    }
};