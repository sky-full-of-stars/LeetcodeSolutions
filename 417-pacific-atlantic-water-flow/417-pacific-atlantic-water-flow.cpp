class Solution 
{
private:
    bool reachPo(int x, int y)
    {
        return (x==0 or y==0);
    }
    bool reachAo(int x, int y)
    {
        return (x==n-1 or y==m-1);
    }
    bool isValid(int x, int y)
    {
        return (x>=0 and y>=0 and x<n and y<m);
    }
    void dfs(int ro, int co, bool &poReached, bool &aoReached, vector<vector<int>>& heights)
    {
        poReached = poReached or reachPo(ro,co);
        aoReached = aoReached or reachAo(ro,co);
        
        if(poReached and aoReached)
            return;
        
        int curHeight = heights[ro][co];
        heights[ro][co] = -1;
        
        for(int i=0; i<4; i++)
        {
            int x = ro +dx[i];
            int y = co +dy[i];
            if(isValid(x,y) and heights[x][y] != -1 and heights[x][y] <= curHeight)
            {
                dfs(x,y,poReached,aoReached,heights);
            }
        }
        heights[ro][co] = curHeight;
    }
    
public:
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>> ans;
        
        n = heights.size();
        m = heights[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                bool poReached = false;
                bool aoReached = false;
                
                dfs(i, j, poReached, aoReached, heights);
                
                if(poReached and aoReached)
                {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};