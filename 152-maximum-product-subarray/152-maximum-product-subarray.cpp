class Solution 
{
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