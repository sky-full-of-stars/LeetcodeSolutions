class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        
        vector<pair<int,int>> numsIdx;
        for(int idx=0; idx<nums.size(); idx++)
        {
            numsIdx.push_back({nums[idx], idx});
        }
        
        sort(numsIdx.begin(), numsIdx.end());
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi)
        {
            if(numsIdx[lo].first + numsIdx[hi].first == target)
            {
                ans.push_back(numsIdx[lo].second);
                ans.push_back(numsIdx[hi].second);
                return ans;
            }
            if(numsIdx[lo].first + numsIdx[hi].first > target)
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