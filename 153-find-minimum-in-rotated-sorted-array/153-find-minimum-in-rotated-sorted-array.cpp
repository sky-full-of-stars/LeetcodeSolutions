class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int lo = 0;
        int hi = nums.size()-1;
        
        //wrote code thinking of following cases:
        //[1]
        //[2,1]        
        //[1,2]       -> shifted 0 times (even len)
        //[1,2,3]     -> shifted 0 times (odd len)
        //[3,1,2]     -> shifted 1 times 
        //[3,4,5,6,1] -> shifted 1 times
        //[6,1,2,3,4] -> shifted n-1 times
        int ans = INT_MAX;
        while(hi >= lo)
        {
            int mid = (lo+hi)/2;
            
            //means, mid lies in greater portion of sorted array 
            if(nums[mid] > nums[hi])
            {
                lo = mid+1;
            }
            else
            {
                // wanted to just have ans = nums[mid]
                // but failed at [3,2,1]
                // hence had to add this check
                ans = min(ans, nums[mid]);
                hi = mid-1;
            }
        }
        return ans;
        
    }
};