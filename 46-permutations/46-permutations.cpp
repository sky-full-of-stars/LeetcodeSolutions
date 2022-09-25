class Solution 
{
private:
    void generate(vector<int> &vis, vector<int> &nums, int &cur, vector<int> &ds)
    {
        if(cur == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        /*
        initially when cur = 0, any element can be first element
        then after placing some element at 0th idx, 
        for 1st idx we again can consider n-1 unvisited elements
        so on...
        after a dfs path is traversed to take other path ie to consider other options,
        we need to undo whats done. ie backtrack.
        */
        for(int i=0; i<nums.size(); i++)
        {
            if(!vis[i])
            {
                ds[cur] = nums[i];
                cur++;
                vis[i] = 1;
                
                generate(vis, nums, cur, ds);
                
                vis[i] = 0;
                cur--;
                ds[cur] = -1;
            }
        }
    }
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> ds(n, -1);
        int curIdx = 0;
        generate(vis, nums, curIdx, ds);
        return ans;
    }
};