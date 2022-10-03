class Solution 
{
private:
    int ways(int curIdx, string &s, int &n, vector<int> &dp)
    {
        if(dp[curIdx] != -1)
        {
            return dp[curIdx];
        }
        
        if(curIdx == n) // "1" -> ans = ways(n,...) = 1
        {
            return dp[n] = 1;
        }
        
        //consider single digit
        if(s[curIdx] == '0')
        {
            return dp[curIdx] = 0;
        }
        int ans = ways(curIdx+1, s, n, dp);
        
        //consider 2 digits
        if(curIdx+1<n and 
                    ((s[curIdx] == '1') or (s[curIdx]=='2' and s[curIdx+1] < '7'))  )
        {
            ans += ways(curIdx+2, s, n, dp);
        }
        return dp[curIdx] = ans;
    }
    
public:
    int ans = 0;
    int numDecodings(string s) 
    {
        int n = s.length();
        if(!n)
            return 0;
        
        vector<int> dp(n+1,-1);
        return ways(0, s, n, dp);
    }
};