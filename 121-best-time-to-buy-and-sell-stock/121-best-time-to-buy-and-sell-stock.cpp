class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int mx = 0;
        int mnSoFar = INT_MAX;
        int ans = 0;
        for(int i: prices)
        {
            if(i > mnSoFar)
            {
                ans = max(ans, i-mnSoFar);
            }
            else
            {
                mnSoFar = i;
            }
        }
        return ans;
    }
};