class Solution
{
public:
    // bool canJump(vector<int>& nums) 
    // {
    //     int n = nums.size();
    //     int mxReach = 0;
    //     for(int i=0; i<=mxReach; i++)
    //     {
    //         mxReach = max(mxReach, i+ nums[i]);
    //         if(mxReach >= n-1)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
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
                return true;
            
            if(range.second < range.first)
                return false;
        }
        return true;
    }
    
};