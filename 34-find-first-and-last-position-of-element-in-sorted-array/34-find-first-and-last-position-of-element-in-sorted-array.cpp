class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int lo = 0; 
        int hi = nums.size()-1;
        int first = -1, last = -1;
        
        //finding last occurance
        while(hi >= lo)
        {
            int mid = (hi+lo)/2;
            
            //definetly doesnt exist here, easily discard
            if(nums[mid] > target)
            {
                hi = mid-1;
            }
            //might exist
            else
            {
                // since we are checking for last occurance you need to plan to have this check in block where                   // you'll move right
                // so once you find element, record its place & move right
                if(nums[mid] == target)
                    last = mid;    
                lo = mid+1; 
            }
        }
        
        //finding first occurance
        lo = 0; 
        hi = nums.size()-1;
        while(hi >= lo)
        {
            int mid = (hi+lo)/2;
        
            //definetly doesnt exist here, easily discard
            if(nums[mid] < target)
            {
                lo = mid+1;
            }
            //might exist
            else
            {
                //since we are planning to find first occurance, we'll find element & move left 
                // move left is possible only for hi
                // hence added check in this block
                // whatever range can be discarded was put for lo check.
                if(nums[mid] == target)
                    first = mid;
                hi = mid-1;
            }
        }

        return {first,last};
    }
};