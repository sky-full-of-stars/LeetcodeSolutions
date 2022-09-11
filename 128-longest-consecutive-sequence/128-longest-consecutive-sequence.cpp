class Solution {
public:
    int longestConsecutiveBrute(vector<int>& nums) 
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
    
    int longestConsecutive(vector<int>& nums) 
    {
        int n= nums.size();
        int ans = 0;
        
        unordered_set<int> numSet;
        for(int i: nums)
            numSet.insert(i);
        
        for(int i: numSet)
        {
            if(numSet.find(i-1) != numSet.end())
            {
                continue;
            }
            int sz = 1;
            int cur = i;
            while(true)
            {
                if(numSet.find(cur+1)!= numSet.end())
                {
                    sz++;
                    cur++;
                }
                else
                    break;
            }
            ans = max(ans, sz);
        }
        return ans;
    }
    
    
};