class Solution 
{
private:
    void generateValidCombination(vector<int>& candidates, int idx, int target, vector<int>& ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if(target < 0 or idx >= candidates.size())
        {
            return;
        }
        
        ds.push_back(candidates[idx]);
        generateValidCombination(candidates, idx, target- candidates[idx], ds);
        ds.pop_back();
        
        generateValidCombination(candidates, idx+1, target, ds); 
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> ds;
        generateValidCombination(candidates, 0, target, ds);
        return ans;
    }
};