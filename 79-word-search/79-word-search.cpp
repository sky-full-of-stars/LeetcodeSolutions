class Solution {
    
private:
    bool wordSearch(int cur, int row, int col, vector<vector<bool>> &vis, int &n, int &m, vector<vector<char>>& board, string &word)
    {
        if(cur == word.length())
        {
            return true;
        }
        
        if(row < 0 or row >= n or col < 0 or col >= m)
        {
            return false;
        }
        
        if(board[row][col] != word[cur] or vis[row][col])
        {
            return false;
        }
        
        vis[row][col] = true;
        bool ans;
        for(int i=0; i<4; i++)
        {
            int x = row + dx[i];
            int y = col + dy[i];
            ans = ans or wordSearch(cur+1, x, y, vis, n, m, board, word);
        }
        vis[row][col] = false;
        return ans;
    }
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        //using convention n rows m cols
        int n = board.size(); 
        int m = board[0].size();
        int cur = 0;
        int row = 0;
        int col = 0;
       
        vector<vector<bool>> vis( n, vector<bool>(m,0) );
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(wordSearch(cur, i, j, vis, n, m, board, word))
                    return true;
            }
        }
        
        return false; 
    }
};