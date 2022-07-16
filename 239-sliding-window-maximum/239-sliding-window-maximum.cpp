class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        
        int start= 0, end = 0;
        while(end < n)
        {
            while(!dq.empty() and dq.back()<nums[end])
            {
                dq.pop_back();
            }
            dq.push_back(nums[end]);
            
            if(end-start+1 < k)
            {
                end++;
            }
            else
            {
                ans.push_back(dq.front());
                
                if(dq.front() == nums[start])
                {
                    dq.pop_front();
                }
                
                start++;
                end++;
            }
        }
        return ans;
    }
};