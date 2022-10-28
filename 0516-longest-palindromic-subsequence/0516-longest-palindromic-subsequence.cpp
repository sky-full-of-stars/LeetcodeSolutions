class Solution 
{
public:
    /*
    tabulation is intuitive enough once you write down 1st string row-wise 
    & second string column-wise.
    & think, if I have 'i' characters from first string & 'j' from second
    how would I fill outlined matrix. 
    start with base cases i=1, j=1
    next figure out for i=1, any j & vice versa
    */
    int longestPalindromeSubseq(string s)
    {
        string text1 = s;
        reverse(s.begin(),s.end());
        string text2 = s;
        
        int n = text1.size();
        int m = text2.size();
        
        /*
        considering 1 extra size to handle edge/corner cases of table
        if you dont want to follow this method, you can have n*m size 
        and initialize 1st row and column in independent block of code(outisde loop)
        */    
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    //idea explained below
    int longestPalindromeSubseqAnotherApproach(string s)
    {
        string text1 = s;
        reverse(s.begin(),s.end());
        string text2 = s;
        
        int n = text1.size();
        int m = text2.size();
        
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    cur[j] = prev[j-1] + 1;
                }
                else
                {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        
        return cur[m];
    }
};
/*

since to fill current row, we only need prev row:
we need only dp[2][m+1]
since we dont want to play arround modulo, 
we keep 2 1d array with size m+1
lets call it prev & cur
implying: we're filing cur row using previously filled prev row.
once thr cur row is completely filled, you guessed it right!
it serves 'prev' for next row to be filled

simply put, I can write solution for 2d matrix 
& replace dp[i][k] with cur[k]
& replace dp[i-1][k] with prev[k]
ie, replace text "dp[i]"" with "cur"
& replace text "dp[i-1]" with "prev"

*/
