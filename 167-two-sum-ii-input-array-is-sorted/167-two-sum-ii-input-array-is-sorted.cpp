class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size(); 
        vector<int> ans;
        
        int lo = 0;
        int hi = n-1;
        while(lo<hi)
        {
            int sum = nums[lo]+nums[hi];
            if(sum == target)
            {
                ans.push_back(lo+1);
                ans.push_back(hi+1);
                return ans;
            }
            if(sum > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return ans;
    }
};