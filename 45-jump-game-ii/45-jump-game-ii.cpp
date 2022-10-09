class Solution 
{
    
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        pair<int,int> range = {0,0};
        int jumps = 0;
        int mxReach = 0;
        while(true)
        {
            jumps++;
            
            for(int i= range.first; i<= range.second; i++)
                mxReach = max(mxReach, i + nums[i]);
            
            range = {range.second+1, mxReach};
            
            if(mxReach >= n-1)
            {
                return jumps;
            }
        }
        return jumps;
    }
    
};