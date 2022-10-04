class Solution
{
private:
    bool util(string &s)
    {
        //if already calculated before, return ans
        if(dp.find(s) != dp.end())
        {
            return dp[s];
        }
        
        //if string exists in dictionary return true
        if(dictMap[s])
        {
            return dp[s] = true;
        }
        
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            string prefix = s.substr(0, i+1);
            string suffix = s.substr(i+1, n-i-1);
            
            if(dictMap[prefix]) // for a valid prefix
            {
                if(util(suffix)) // lets search if valid wordBreak suffix exists
                {
                    ans = true;
                }
            }
        }
        
        dp[s] = ans;
        return ans;
    }
public:
    map<string, bool> dictMap;
    bool ans = false;
    int n;
    map<string, int> dp;
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        n = s.length();
        
        for(string word: wordDict)
            dictMap[word] = true;
        
        return util(s);
        
    }
};