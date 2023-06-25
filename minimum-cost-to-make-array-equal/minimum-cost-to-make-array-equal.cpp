class Solution 
{
private:
    //-----------------------------------------------------------------------//
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
    //-----------------------------------------------------------------------//
    long long solveUsingBinarySearchOnConvexFunction(vector<int>& nums, vector<int>& cost)
    {
        return 0;
    }

    long long solveUsingPrefixSums(vector<int>& nums, vector<int>& cost)
    {
        return 0;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        int random = 0; //rand()%3;
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
            return solveUsingPrefixSums(nums, cost);
        }
        return 0;
    }
};