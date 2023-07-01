class Solution {
public:
    int n,k;
    int mxSum;
    int ans = INT_MAX;
    void solve(int cookieNo, vector<int>& cookies, vector<int>& sums, int unfairness)
    {
        if(cookieNo == n)
        {
            ans = min(ans, unfairness);
            return;
        }
        
        for(int kid=0; kid<k; kid++)
        {
            sums[kid] += cookies[cookieNo];
            int curUnfairness = max(unfairness, sums[kid]);
            solve(cookieNo+1, cookies, sums, curUnfairness);
            sums[kid] -= cookies[cookieNo];
        }
    }
    int distributeCookies(vector<int>& cookies, int _k) 
    {
        n = cookies.size();
        k = _k;
        vector<int> sums(k,0);
        
        int unfairness = INT_MIN;
        solve(0, cookies, sums, unfairness);
        
        return ans;
    }
};