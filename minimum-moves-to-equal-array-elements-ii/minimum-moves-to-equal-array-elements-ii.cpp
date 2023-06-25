class Solution {
public:
    int moves(int to, vector<int>& nums)
    {
        int ans =0;
        for(auto i: nums)
        {
            ans += abs(i-to);
        }
        return ans;
    }
    int minMoves2(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n&1)
        {
            return moves(nums[n/2], nums);
        }    
        return min(moves(nums[n/2],nums), moves(nums[n/2-1],nums));
    }
};