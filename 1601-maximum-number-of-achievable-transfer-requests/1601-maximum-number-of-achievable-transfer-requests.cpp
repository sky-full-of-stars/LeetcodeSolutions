class Solution {
private:
    bool checkIfNoNetChange(vector<int>& changeArr)
    {
        for(auto i: changeArr)
        {
            if(i)
                return false;
        }
        return true;
    }
public:
    /*
    I can select any combination of requests possible since n<=16
    every request has 2 possibilty. select/ ignore
    so n such requests in totality have 2^n combinations
    worst case O(2^16) -> O((2^3)^5) -> O(10^5) should be within 1 sec limit
    */
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        int ans =0;
        int sz = requests.size();
        
        for(int mask=0; mask<(1<<sz); mask++)
        {
            vector<int> deltaInBuildingPopulation(n, 0);
            
            for(int requestNo=0; requestNo<sz; requestNo++)
            {
                if(mask&(1<<requestNo))
                {
                    int from = requests[requestNo][0];
                    int to = requests[requestNo][1];
                    deltaInBuildingPopulation[from]--;
                    deltaInBuildingPopulation[to]++;
                }
            }
            
            if(checkIfNoNetChange(deltaInBuildingPopulation))
            {
                int numOfRequestsHonored = __builtin_popcount(mask);
                ans = max(ans, numOfRequestsHonored);
            }
        }
        
        return ans;
    }
};