class Solution 
{
private :
    int robLinearHouse(vector<int>& nums, int l, int r)
    {
        int prev = 0;
        int prevPrev = 0;
        
        for(int i=l; i<=r;i++)
        {
            int chooseCur = nums[i] + prevPrev;
            int notChooseCur = prev;
            int cur = max(chooseCur, notChooseCur);
            
            prevPrev = prev;
            prev = cur;  
        }
        return max(prev, prevPrev);      
    }    
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int N = n-1;
        if(n == 1)
            return nums[0];

        return max(robLinearHouse(nums,0, n-2), robLinearHouse(nums, 1, n-1));
        
    }
};