class Solution 
{
private:

    //WEIGHTED MEDIAN SOLUTION
    //-----------------------------------------------------------------------------------------------------------------------------//
    int getMedian(vector<pair<long long,long long>>& v)
    {
        long long sz = 0ll;
        for(auto [f,s]: v)
            sz += s;

        int median = -1;
        long long curTotal = 0, i = 0;
        while(i < v.size() and curTotal < (sz+1)/2)
        {
            curTotal = curTotal + 1ll*v[i].second;
            median = v[i].first;
            i++;
        }
        return median;
    }
    long long getCost(vector<pair<long long,long long>>& v, int x)
    {
        long long res =0ll;
        for(int i=0; i<v.size(); i++)
        {
            res = res + ( 1ll * abs(v[i].first - x) * v[i].second);
        }
        return res;
    }
    long long solveUsingWeightedMedian(vector<int>& nums, vector<int>& cost)
    {
        int n = nums.size();

        vector<pair<long long,long long>> v;
        for(int i=0; i<n; i++)
        {
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end());

        int median = getMedian(v);
        return getCost(v, median);
    }




    //BINARY SEARCH ON CONVEX FUNCTION SOLUTION
    //-----------------------------------------------------------------------------------------------------------------------------//
    long long getCost(vector<int>& nums, vector<int>& cost, int convertAllTo)
    {
        long long totCost = 0l;
        for(int i=0; i<nums.size(); i++)
        {
            totCost = totCost + (1LL*cost[i]*(abs(nums[i]-convertAllTo)));
        }
        return totCost;
    }
    // I wouldnt call it ternary search only coz, 
    // we are not technically dividing array into 3 search fragments and discarding 2
    long long solveUsingBinarySearchOnConvexFunction(vector<int>& nums, vector<int>& cost)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        // while making bold assumptions like this,
        // make sure we'll get right answer for corner cases,
        // ie when array has 0 or 1 or 2 or 3 or 4 elements.
        long long ans = LLONG_MAX;
        while(l <= r)
        {
            int mid1 = (l+r)/2;
            int mid2 = mid1+1;
            
            long long cost1 = getCost(nums, cost, mid1);
            long long cost2 = getCost(nums, cost, mid2);

            ans = min(cost1, cost2);

            if(cost1 > cost2)
                l = mid1+1;
            else
                r = mid1-1;    
        }
        return ans;
    }




    //PREFIX SUM DP SOLUTION
    //-----------------------------------------------------------------------------------------------------------------------------//
    long long solveUsingPrefixSumsDP(vector<int>& nums, vector<int>& cost)
    {
        int n = nums.size();

        vector<pair<int,int>> vpi;
        for(int i=0; i<n; i++)
        {
            vpi.push_back({nums[i], cost[i]});
        }
        sort(vpi.begin(), vpi.end());

        vector<long long> prefixSums(n);
        prefixSums[0] = vpi[0].second;
        for(int i=1; i<n; i++)
        {
            prefixSums[i] = prefixSums[i-1]+vpi[i].second;
        }

        vector<long long> dp(n,0);
        for(int i=1; i<n; i++)
        {
            dp[0] = dp[0] + (1ll* vpi[i].second * abs(vpi[i].first- vpi[0].first));
        }
        for(int i=1; i<n; i++)
        {
            int gap = vpi[i].first - vpi[i-1].first;
            dp[i] = dp[i-1] 
                    + (prefixSums[i-1]* gap)
                    - (prefixSums[n-1]- prefixSums[i-1])*gap;
        }
        //note that to calc dp[i] we only need dp[i-1]
        //so space complexity can be reduced to O(1)
        //but not doing it for readability.
        return *min_element(dp.begin(), dp.end());
    }
    //-----------------------------------------------------------------------------------------------------------------------------//




public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        int random = rand()%3;
        if(random == 0)
        {
            return solveUsingWeightedMedian(nums, cost);
        }
        if(random == 1)
        {
            return solveUsingBinarySearchOnConvexFunction(nums, cost);
        }
        if(random == 2)
        {
            return solveUsingPrefixSumsDP(nums, cost);
        }
        return random;
    }
};