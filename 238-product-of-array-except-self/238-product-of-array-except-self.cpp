class Solution {
public:
    vector<int> productExceptSelfBrute(vector<int>& nums)
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
    
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n,1);
        
        //let ans contain cumulative prefixProd
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            ans[i] = ans[i-1]*nums[i-1];
        }
        
        //lets multiply suffixProd now from the end
        int suffixProd = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = ans[i]*suffixProd;
            suffixProd *= nums[i];
        }
        
        return ans;
        
    }
};