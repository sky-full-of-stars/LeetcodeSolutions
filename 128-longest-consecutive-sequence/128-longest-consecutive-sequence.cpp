class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n= nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        for(int start=0;start<n;)
        {
            int prev = nums[start];
            int end = start+1;
            int rep = 0;
            while(end<n and (nums[end]==prev or nums[end] == prev+1))
            {
                if(nums[end] == prev)
                    rep++;
                prev = nums[end];
                end++; 
            }
            int curLen = end-start-rep;
            ans = max(curLen, ans);
            start = end;
        }
        
        return ans;
    }
};