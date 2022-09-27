class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        //transpose
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        //reverse
        for(int row=0; row<n; row++)
            reverse(matrix[row].begin(), matrix[row].end());
    }
};