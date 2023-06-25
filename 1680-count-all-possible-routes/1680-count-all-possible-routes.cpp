const int mod = 1000 * 1000 * 1000 + 7;
class Solution 
{
    int n;
    public:
        int dp[101][201];
        int ways(int s, int e, vector<int>& locations, int fuel)
        {
            if(dp[s][fuel] != -1)
            {
                return dp[s][fuel];
            }

            int ans = (s==e)? 1 : 0;
            for(int i=0; i<locations.size(); i++)
            {
                if(i == s)
                {
                    continue;
                }

                int fuelNeed = abs(locations[s]- locations[i]);
                if(fuelNeed <= fuel)
                {
                    ans = (ans+ ways(i, e, locations, fuel - fuelNeed))%mod;
                }    
            }
            return dp[s][fuel] = ans;
        }
        int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
        {
            n = locations.size();
            memset(dp, -1, sizeof dp);
            return ways(start, finish, locations, fuel);    
        }
};