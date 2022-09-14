class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.length();
        int lo=0, hi=0;
        
        int mxRepeated = 0;
        int ans= 0;
        map<char,int> cnt;
        while(hi<n)
        {
            char cur = s[hi];
            cnt[cur]++;
            mxRepeated = max(mxRepeated, cnt[cur]);
            //lhs : num of substitutions
            // lhs > k -> invalid window
            // while invalid window -> slide left, make it valid.
            //
            while((hi-lo+1)-mxRepeated > k)
            {
                cnt[s[lo]]--;
                lo++;
                //most important observation is we're not changing mxRepeated here!
                //this is because even if I decrease mxRepeated, 
                //numOfSubstitutions increase -> which anyway wont affect our final answer.
                //to get current answer, we consider we've considered "mxRepeated" amount of common elements.
                //even if we consider lesser elements, we'll just get lesser answer.
                //but anyway, its not very intuitive. its just observational for me now.
                
                // brute force approach would be update mxRepeated in this while loop everytime we do lo++;
            }
            ans = max(ans, hi-lo+1);

            hi++;
        }
        return ans;
        
    }
};