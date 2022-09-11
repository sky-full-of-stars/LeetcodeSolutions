class Solution {
    
private: 
    int charToInt(char c)
    {
        return c-'0';
    }
    bool validValues(vector<int> val)
    {
        vector<int> count(10,0);
        for(int i: val)
        {
            count[i]++;
            if(count[i]>1)
            {
                return false;
            }
        }
        return true;
    }
    bool boxCheck(vector<vector<char>>& board)
    {
        for(int row =0; row<8; row+=3)
        {
            for(int col=0; col<8; col+=3)
            {
                vector<int> values;
                for(int i= row; i<row+3; i++)
                {
                    for(int j= col; j<col+3; j++)
                    {
                        if(board[i][j]!='.')
                        {
                            values.push_back(charToInt(board[i][j]));
                        }
                    }
                }
                if(!validValues(values))
                    return false;
            }
        }
        return true;
    }
    bool rowCheck(vector<vector<char>>& board)
    {
        for(int row =0; row<9; row++)
        {
            vector<int> values;
            for(int col=0;col<9;col++)
            {
                if(board[row][col]!='.')
                {
                    values.push_back(charToInt(board[row][col]));
                }
            }
            if(!validValues(values))
                return false;
        }
        return true;
    }
    bool colCheck(vector<vector<char>>& board)
    {
        for(int col =0; col<9; col++)
        {
            vector<int> values;
            for(int row=0; row<9; row++)
            {
                if(board[row][col]!='.')
                {
                    values.push_back(charToInt(board[row][col]));
                }
            }
            if(!validValues(values))
                return false;
        }
        return true;
    }
    
    
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        if(rowCheck(board) and colCheck(board) and boxCheck(board))
            return true;
        return false;
    }
};