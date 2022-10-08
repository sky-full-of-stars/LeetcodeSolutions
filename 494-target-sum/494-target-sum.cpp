class Solution 
{
private:
    void countValidSymbolCombinations(string s, int n, vector<int> &nums, int &targetSum, int &ans)
    {
        if(!n)
        {
            if(evaluateExpression(s, nums, targetSum))
            {
                ans++;
            }
            return;
        }
        countValidSymbolCombinations(s+"+", n-1, nums, targetSum, ans);
        countValidSymbolCombinations(s+"-", n-1, nums, targetSum, ans);
    }
    
    bool evaluateExpression(string symbol, vector<int> &nums, int targetSum)
    {
        int n = nums.size();
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
           if(symbol[i] == '+')
               ans += nums[i];
            else
                ans -= nums[i];
        }
        return (ans == targetSum);
    }
    
    int util(int curSum, int curIdx, int &target, vector<int> &nums)
    {
        if( dp.find({curSum, curIdx}) != dp.end() )
        {
            return dp[{curSum, curIdx}];
        }
        
        if(curIdx == n) 
        {
            if(curSum == target)
                return 1;
            else
                return 0;
        }
        
        int positivesSum = util(curSum + nums[curIdx], curIdx+1, target, nums);
        int negativesSum  = util(curSum - nums[curIdx], curIdx+1, target, nums);
        return dp[{curSum, curIdx}] = positivesSum + negativesSum;  
    }
    
public:
    map<pair<int,int>, int> dp;
    int n;
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int ans = 0;
        //countValidSymbolCombinations("", nums.size(), nums ,target, ans);
        //return ans;
        
        n = nums.size();
        return util(0, 0, target, nums);
    }
};