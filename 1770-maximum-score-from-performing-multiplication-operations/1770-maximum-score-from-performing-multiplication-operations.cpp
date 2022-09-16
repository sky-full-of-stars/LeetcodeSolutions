class Solution {
    
private:
    //map< pair<int,int>, int> dp;
    vector<vector<int>> dp;
    
    int getProd(int lo, int i, vector<int>& nums, vector<int>& multipliers)
    {
        int hi = nums.size() -1 - i + lo;
        
        if(dp[lo][i]!= INT_MIN)
            return dp[lo][i];
        
        if(i == multipliers.size() or lo>hi )
            return 0;
        
        int leftIncluded  = (nums[lo]*multipliers[i]) + getProd(lo+1,i+1, nums, multipliers);
        int rightIncluded = (nums[hi]*multipliers[i]) + getProd(lo, i+1, nums, multipliers);
        return dp[lo][i] = max(leftIncluded, rightIncluded);
    }
    
public:
        int maximumScore(vector<int>& nums, vector<int>& multipliers) 
        {
            int n = nums.size();
            int m = multipliers.size();
            dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
            return getProd(0, 0, nums, multipliers);
        }
};


