class Solution 
{
private:
    set<vector<int>> subsetsBitManipulation(vector<int>& nums)
    {
        int n = nums.size();
        int lo = 0;
        int hi = 1<<n;

        for(int ele = lo; ele<hi; ele++)
        {
            vector<int> subset;
            for(int i=0; i<nums.size(); i++)
            {
                bool ithBitSet = ((ele & (1<<i)) != 0);
                if(ithBitSet)
                    subset.push_back(nums[i]);
            }
            ans.insert(subset);
        }
        return ans;
    }
public:
    set<vector<int>> ans;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        subsetsBitManipulation(nums);
        
        for(auto i: ans) 
            res.push_back(i);
        
        return res;
    }
};