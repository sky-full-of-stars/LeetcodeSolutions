class Solution 
{
    /*
easy solution to think. 
tricky implementation.

A) we always want to consider positives.

B) with negatives 2 cases:
    1) even num of negatives: consider all of them
    2) odd num of negatives : 
        a) ignore either 1st odd num or
        b) last odd num. 
        consider everything in between.
        And,
        value for 
            a) ans = suffix prod of all till 1st negative num
            b) ans = prefix prod of all till last negative num
            
C) with 0 in between, calculate ans for all non	zero subsequences.
*/
    
public:
    int maxProduct(vector<int>& nums)
    {
        int prefixProd = 1;
        int suffixProd = 1;
        int n = nums.size();
        
        int res = INT_MIN;
        for(int i=0; i<n; i++)
        {
            prefixProd = (prefixProd? prefixProd : 1) * nums[i];
            suffixProd = (suffixProd? suffixProd : 1) * nums[n-1-i];
            res = max(res, max(prefixProd, suffixProd));
        }
        
        return res;   
    }
};