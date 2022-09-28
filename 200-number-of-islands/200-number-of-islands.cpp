class Solution {
private:
    bool valid(int x, int y)
    {
        return (x>=0 and y>=0 and x<roSz and y <coSz);
    }
    void dfs(int ro, int co, vector<vector<char>>& grid)
    {
       grid[ro][co] = 'v';
        
       for(int i=0; i< 4; i++)
       {
           int x = ro + dx[i];
           int y = co + dy[i];
           if(valid(x,y) and grid[x][y] == '1')
           {
               dfs(x,y,grid);
           }
       } 
    }
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int roSz, coSz;
    int numIslands(vector<vector<char>>& grid) 
    {
        roSz = grid.size();
        coSz = grid[0].size();
        
        int count = 0;
        
        for(int i=0; i<roSz; i++)
        {
            for(int j=0; j<coSz; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};