class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int lo = 0, hi = n-1;
        while(hi > lo)
        {
            int mid = (lo + hi + 1)/2;
            
            if(matrix[mid][0] > target)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid;
            }
        }
        
        int row = lo;
        lo = 0, hi = m-1;
        while(hi > lo)
        {
            int mid = (lo + hi + 1)/2;
        
            if(matrix[row][mid] > target)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid;
            }
        }
        return (matrix[row][lo] == target);
        
        /*
        another approach would be to treat matrix as 1d sorted array
        [[1,3,5,7],[10,11,16,20],[23,30,34,60]] becomes [1,3,5,7,10,11,16,20,23,30,34,60]
        so lo=0, hi = (m*n -1) to start with
        calculate mid
        row and col corresponding to mid is (mid/m) and (mid%m) respectively.
        */
    }
};