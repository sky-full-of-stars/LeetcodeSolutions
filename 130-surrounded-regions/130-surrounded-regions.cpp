class Solution 
{
private:
    bool corner(int i, int j)
    {
        return (i==0 or j==0 or i==n-1 or j==m-1);
    }
    bool valid(int i, int j)
    {
        return (i>=0 and j>=0 and i<=n-1 and j<=m-1);
    }
    void dfs(int ro,int co, vector<vector<char>> &board)
    {
        board[ro][co] = 'V';
        for(int i=0; i<4;i++)
        {
            int x = ro+dx[i];
            int y = co+dy[i];
            if(valid(x,y) and board[x][y] == 'O')
                dfs(x,y,board);
        }
    }
public:
    int n,m;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    void solve(vector<vector<char>>& board) 
    {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(corner(i,j)  and board[i][j] == 'O')
                    dfs(i,j,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'V')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};