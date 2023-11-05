
class Solution {
public:
    static const int N = 2e4 + 7;
    vector<int> gp[N];
    vector<int> value;
    map<int, long long> subTreeSum; 
    
    long long min(long long x, long long y)
    {
        return x<=y?x:y;
    }
    
    bool isLeaf(int n)
    {
        if(gp[n].size() == 1)
            return true;
        return false;
    }
    
    /*
        minValueToKeep for a subtree under root is the minimum sum of values retained under that tree so that subtree is           healthy.
    */
    long long minValueToKeep = LLONG_MAX;
    long long subTreeTotalSum = 0ll;
    void dfs(int root, int par)
    {
        subTreeTotalSum += value[root];
        if(isLeaf(root))
        {
            subTreeSum[root] = value[root];
            return;
        }
        for(int child: gp[root])
        {
            if(child != par)
            {
                dfs(child, root);
            }
        }
        long long sum = 0ll;
        for(int child: gp[root])
        {
            sum += subTreeSum[child];
        }
        minValueToKeep = min(value[root], sum);
        subTreeSum[root] = min(value[root] , sum);
    }
    
    
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        value = values;
        
        for(auto i: edges)
        {
            gp[i[0]].push_back(i[1]);
            gp[i[1]].push_back(i[0]);
        }
        
        long long totalScore = 0;
        for(auto i: gp[0])
        {
            dfs(i,0);
            minValueToKeep = (minValueToKeep == LLONG_MAX ? subTreeTotalSum : minValueToKeep);
            
            long long subTreeContribution = subTreeTotalSum - minValueToKeep;
            totalScore += subTreeContribution;
            
            // cout<<i<<"->"<<minValueToKeep<<endl;
            // cout<<i<<"->"<<subTreeContribution<<endl;
            
            minValueToKeep = LLONG_MAX;
            subTreeTotalSum = 0ll;
        }
        totalScore += value[0];
        //cout<<totalScore<<endl;
        
        long long aggr = accumulate(values.begin(), values.end(), 0ll);
        long long sacrificeRoot =  aggr-value[0];
        //cout<<aggr<<" "<<sacrificeRoot<<endl;
        return max(totalScore, sacrificeRoot);
    }
};