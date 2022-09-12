class Solution {
public:
    int maxArea(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        
        //ans = height * width
        //ans is max when height is max and width is max
        //keeping width as max, then calculating area (using l and h as borders)
        //then decrease width smartly by choosing to include maxHeight among l and h
        //repeat the same. 
        //of all areas choose best one
        int lo = 0, hi=n-1;
        while(lo<hi)
        {
            int cur = (hi-lo)*(min(nums[lo],nums[hi]));
            ans = max(ans, cur);             
            
            if(nums[lo]<nums[hi])
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
        return ans;
        
        
    }
};


