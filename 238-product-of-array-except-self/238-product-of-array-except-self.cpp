class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        
        vector<int> prefixProd(n);
        prefixProd[0] = 1;
        for(int i=1;i<n;i++)
        {
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }
        
        
        vector<int> suffixProd(n);
        suffixProd[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            suffixProd[i] = suffixProd[i+1] * nums[i+1];
        }
        
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(prefixProd[i]*suffixProd[i]);
        }
        return ans;
    }   
};