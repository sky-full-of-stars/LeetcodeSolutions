class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.length();
        int ans = 0;
        
        int lo=0,hi=0;
        map<char,int> mp;
        
        while(hi<n)
        {
            mp[s[hi]]++;
            if(mp.size() == hi-lo+1)
            {
                ans = max(ans, hi-lo+1);
            }
            else
            {
                while(mp.size() < (hi-lo+1))
                {
                    mp[s[lo]]--;
                    if(mp[s[lo]] == 0) 
                    {
                        mp.erase(s[lo]);
                    }
                    lo++;
                }
            }
            
            hi++;
        }
        return ans;
        
    }
};