class Solution {
public:
    string minWindow(string s, string t) 
    {
        int lo=0,hi=0;
        int mn = INT_MAX;
        string ans ="";
        int n = s.size();
        
        map<char,int> reqdMp;
        for(char i: t) reqdMp[i]++;
        int uniqueReqdCnt = reqdMp.size();
        
        while(hi<n)
        {
            char cur = s[hi];
            reqdMp[cur]--;
            if(reqdMp[cur] == 0)
            {
                uniqueReqdCnt--;
            }
            if(uniqueReqdCnt == 0)
            {
                if(hi-lo+1 < mn)
                {
                    mn = hi-lo+1;
                    ans = s.substr(lo, hi-lo+1);
                }
                while(true)
                {
                    reqdMp[s[lo]]++;   
                    if(reqdMp[s[lo]] == 1)
                    {
                        //found a valid window by shriking
                        if(hi-lo+1 < mn)
                        {
                            mn = hi-lo+1;
                            ans = s.substr(lo, hi-lo+1);
                        }
                        uniqueReqdCnt++;
                        lo++;
                        break;
                    }
                    lo++;
                }
            }
            hi++;
        }
        return ans;
        
    }
};