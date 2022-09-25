class Solution {

private:
    
public:
    int sz;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums)
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
};