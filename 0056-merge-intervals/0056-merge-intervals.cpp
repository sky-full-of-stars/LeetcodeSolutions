class Solution
{
    
public:
    int start = 0, end = 1;
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i= 1; i<intervals.size(); i++)
        {
            if(intervals[i][start] > ans.back()[end])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[end] = max(ans.back()[end], intervals[i][end]);
            }
        }
        return ans;
    }
};