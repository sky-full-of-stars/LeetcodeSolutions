class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        int n = temp.size();
        vector<int> ans(n,0);    
        
        stack<pair<int,int>> s;
        for(int idx=0;idx<n;idx++)
        {
            int cur = temp[idx];
            if(s.empty() or cur <= s.top().first)
            {
                s.push({cur,idx});
            }
            else
            {
                while(!s.empty() and s.top().first < cur)
                {
                    int lowerTempDay = s.top().second;
                    ans[lowerTempDay] = idx - lowerTempDay;
                    s.pop();
                }
                s.push({cur,idx});
            }
        }
        return ans;
    }
};