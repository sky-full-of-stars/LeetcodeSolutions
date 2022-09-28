class Solution {
private:
    bool valid(int x, int y)
    {
        return (x>=0 and y>=0 and x<roSz and y <coSz);
    }
    void dfs(int ro, int co, vector<vector<int>>& grid, int &curArea)
    {
       curArea++; 
       grid[ro][co] = 0;
        
       for(int i=0; i< 4; i++)
       {
           int x = ro + dx[i];
           int y = co + dy[i];
           if(valid(x,y) and grid[x][y] == 1)
           {
               dfs(x,y,grid, curArea);
           }
       } 
    }
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int roSz, coSz;
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        roSz = grid.size();
        coSz = grid[0].size();
        
        int area = 0;
        
        for(int i=0; i<roSz; i++)
        {
            for(int j=0; j<coSz; j++)
            {
                if(grid[i][j] == 1)
                {
                    int curArea = 0;
                    dfs(i,j,grid, curArea);
                    area = max(area, curArea);
                }
            }
        }
        
        return area;
    }
};