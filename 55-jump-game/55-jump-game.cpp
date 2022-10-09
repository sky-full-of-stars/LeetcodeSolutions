class Solution
{
public:
        bool canJump(vector<int>& nums) 
        {
            int n = nums.size();
            int mxReach = 0;
            for(int i=0; i<=mxReach; i++)
            {
                mxReach = max(mxReach, i+ nums[i]);
                if(mxReach >= n-1)
                {
                    return true;
                }
            }
            return false;
        }
};