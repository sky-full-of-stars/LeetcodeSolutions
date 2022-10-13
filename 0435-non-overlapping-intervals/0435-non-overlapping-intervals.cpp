class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        
        int start = 0, end=1;
        int rBorderOfSelectedInterval = intervals[0][end];
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][start] < rBorderOfSelectedInterval) // overalap
            {
                res++; // remove interval with max endTime so most num of collisions can be avoided
                rBorderOfSelectedInterval = min(rBorderOfSelectedInterval, intervals[i][end]);
            }
            else
            {   // no collision, update endTime
                rBorderOfSelectedInterval = intervals[i][end];
            }
        }
        return res;
    }
};