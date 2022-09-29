class Solution 
{
private:
    int root(int u)
    {
        while(par[u]!= u)
        {
            u = par[par[u]];
        }
        return u;
    }
    bool union_(int u, int v)
    {
        int parU = root(u);
        int parV = root(v);
        
        if(parU == parV)
        {
            return true;
        }
        
        if(sz[parU] > sz[parV])
        {
            cout<<"1"<<endl;
            par[parV] = parU;
            sz[parU] += sz[parV];
        }
        else
        {
            cout<<"2"<<endl;
            par[parU] = parV;
            sz[parV] += sz[parU];
        }
        return false;
    }
public:
    vector<int> par;
    vector<int> sz;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size()+1;
        par.resize(n);
        sz.resize(n,1);
        
        for(int i=1; i<n; i++)
        {
            par[i] = i;
        }
        
        for(auto i: edges)
        {
            if(union_(i[0],i[1]))
            {
               return {i[0],i[1]}; 
            }
        }
        
        return {-1,-1};
    }
};