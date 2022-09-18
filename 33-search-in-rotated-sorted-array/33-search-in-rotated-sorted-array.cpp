class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int lo = 0;
        int hi = nums.size()-1;
        
        //every step decrementing hi or incrementing lo
        //so no need to worry about range not shrinking & infinite loop        
        while(hi >= lo)
        {
            int mid = (lo + hi)/ 2;
            if(nums[mid] == target)
                return mid;
            
            //my idea was to check after getting mid,check which side of array is sorted.
            //if left side is sorted. 
            //then element has to exist either on left or on right
            //if target exists in left range discard right range
            //if target doesnt exist in left range discard left range
            //symmetric propery : do the same if right side is sorted
            
            //sorted from lo to mid
            if(nums[lo] <= nums[mid])
            {
                // target lies between lo & mid. uff. simple. I need to search from lo to mid-1
                // we already have checked if (target == nums[mid]) so no <= for second condition
                if(nums[lo] <= target and target < nums[mid])
                    hi = mid-1;
                // target is not in this range. so need to look from [mid+1] to hi
                else
                    lo = mid+1;
            }
            //sorted from mid to hi
            else
            {
                 // target lies between mid & hi
                 if(nums[mid] < target and target <= nums[hi])
                    lo = mid+1;
                // target is not in this range.
                else
                    hi = mid-1;
            }
        }
        return -1;
    }
};