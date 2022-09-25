class Solution {

private:
    void createSubset(int idx, vector<int> &ds, vector<int> &nums)
    {
        if(idx == sz)
        {
            ans.push_back(ds);
            return;
        }
        
        createSubset(idx+1, ds, nums);
        
        ds.push_back(nums[idx]);
        createSubset(idx+1, ds, nums);
        ds.pop_back();
    }
    
public:
    int sz;
    vector<vector<int>> ans;
    
    //using bit manipulation
    vector<vector<int>> subsetsBitManipulation(vector<int>& nums)
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
            ans.push_back(subset);
        }
        return ans;
    }
    
    //using recursion (backtracking)
    vector<vector<int>> subsets(vector<int>& nums)
    {
        sz = nums.size();
        vector<int> ds;
        createSubset(0, ds, nums);
        return ans;
    }
};