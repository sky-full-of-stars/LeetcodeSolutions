class Solution {
private:
    int solve(int n, vector<int> &cost)
    {
        if(n < 0)
            return 0;
        
        if(n == 0 or n==1)
            return dp[n] = cost[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = cost[n] + min(solve(n-1, cost), solve(n-2, cost));  
    }
    
public:
    vector<int> dp;
    
    // o(n) space, bottom up
    int minCostClimbingStairs(vector<int>& costV)
    {
        int n = costV.size();
        dp.resize(n+1, -1);
        
        return min(solve(n-1, costV), solve(n-2, costV));
    }
    
    // o(n) space, top down
    int minCostClimbingStairsTopDown(vector<int>& costV)
    {
        int n = costV.size();
        dp.resize(n, -1);
        
        dp[0] = costV[0];
        dp[1] = costV[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = costV[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    
    // o(1) space, top down
    int minCostClimbingStairsTopDownConstantSpace(vector<int>& costV)
    {
        int n = costV.size();
        
        int first = costV[0];
        int second = costV[1];
        for(int i=2; i<n; i++)
        {
            int cur= costV[i] + min(first, second); 
            first = second;
            second = cur;
        }
        return min(first, second);
    }
    
    
};