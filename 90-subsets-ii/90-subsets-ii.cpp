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
    
    void createSubset(int idx, vector<int> &ds, vector<int> &nums)
    { 
        res.push_back(ds);
        
        for(int i= idx; i< nums.size(); i++)
        {
            if(i != idx and nums[i] == nums[i-1])
                continue;
            
            ds.push_back(nums[i]);
            createSubset(i+1, ds, nums);
            ds.pop_back();
        } 
    }
    
    
public:
    int sz;
    set<vector<int>> ans;
    vector<vector<int>> res;
    
    vector<vector<int>> subsetsWithDupBrute(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        subsetsBitManipulation(nums);
        
        for(auto i: ans) 
            res.push_back(i);
        
        return res;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sz = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> ds;
        createSubset(0, ds, nums);
        
        return res;
    }

};