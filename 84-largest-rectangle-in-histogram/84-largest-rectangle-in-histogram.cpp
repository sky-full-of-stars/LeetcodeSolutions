class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        
        vector<int> leftMin(n,-1);
        vector<int> rightMin(n,n);
        
        stack<pair<int,int>> s;
        for(int i=n-1; i>=0; i--)
        {
            int cur = heights[i];
            if(s.empty() or cur > s.top().first)
            {
                s.push({cur, i});
            }
            else
            {
                while(!s.empty() and s.top().first>cur)
                {
                    leftMin[s.top().second] = i;
                    s.pop();
                }
                s.push({cur, i});
            }
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i=0; i<n; i++)
        {
            int cur = heights[i];
            if(s.empty() or cur > s.top().first)
            {
                s.push({cur, i});
            }
            else
            {
                while(!s.empty() and s.top().first>cur)
                {
                    rightMin[s.top().second] = i;
                    s.pop();
                }
                s.push({cur, i});
            }
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     cout<<leftMin[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++)
        // {
        //     cout<<rightMin[i]<<" ";
        // }
        // cout<<endl;
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int curRectangleArea = heights[i];
            
            int leftExtra = (i-leftMin[i])-1;
            int rightExtra = (rightMin[i]-i)-1;
            int width = 1 + leftExtra + rightExtra;
            
            curRectangleArea = curRectangleArea*width;
        
            //cout<< curRectangleArea <<" "<<leftExtra <<" "<<rightExtra<<endl;
            ans = max(ans, curRectangleArea);
        }
        return ans;
    }
};