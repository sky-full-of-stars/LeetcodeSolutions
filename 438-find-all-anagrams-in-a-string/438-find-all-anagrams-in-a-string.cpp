class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) 
    {
        int n = s2.length();
        vector<int> ans;
        
        map<char,int> cnt;
        for(char i: s1) cnt[i]++;
        int uniqueChars = cnt.size();
        
        int lo=0,hi = 0;
        int charsNeeded = uniqueChars;     // desired num of unique chars to be present in s2's window.
        map<char,int> windowMpReqt = cnt;  //desired chars with its cnt in window
        
        while(hi<n)
        {
            char cur = s2[hi];
            
            //if cur ele in s2 is not in s1 -> invalid window
            //start new window. reset all values again.
            if(cnt[cur] == 0)
            {
                lo = hi+1;
                hi = hi+1;
                windowMpReqt = cnt;
                charsNeeded = uniqueChars;
                continue;
            }
            else
            {
                windowMpReqt[cur]--;
                
                //hits desired target of reqd count for char 'cur'
                if(windowMpReqt[cur] == 0)
                    charsNeeded--;
                
                //if(windowMpReqt[cur] < 0), dont worry. dont slide here itself. 
                //first let window size hit. then slide away unnecessary chars.
                //s1: ab s2:aabc
                //dont complicate by sliding window here. slide always once fixed window size is hit.
            }
            
            //window size hit
            if(hi-lo+1 == s1.size())
            {
                //check if its valid answer
                if(charsNeeded == 0)
                    ans.push_back(lo);
                
                //start sliding window from behind
                windowMpReqt[s2[lo]]++;   
                //some char's reqt was earlier 0, hence we had decremented charsNeeded
                //now it's count is incremented and has become 1, so undo it. we need to look for it again.
                if(windowMpReqt[s2[lo]] == 1)
                    charsNeeded++;
                //changes undone, slide
                lo++;
            }
            hi++;
        }
        return ans;
    }
};