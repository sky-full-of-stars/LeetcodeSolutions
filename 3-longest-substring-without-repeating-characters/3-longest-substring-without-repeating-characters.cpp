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
                    else
                    {
                        // no need to remove char from mp if its current elements duplicate element. it'll just become mp[curEle]=1
                        // other equivalent of if block is : if(s[lo]!=s[hi]){mp.erase[s[lo]];}
                        // that means erase completely from map only if its not cur element.
                        
                        // you can also erase current element and then add mp[s[hi]]++ in the end. even that should work. 
                    }
                    lo++;
                }
            }
            
            hi++;
        }
        return ans;
        
    }
};