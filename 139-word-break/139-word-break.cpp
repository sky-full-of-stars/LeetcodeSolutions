class Solution
{
private:
    bool util(string &s)
    {
        if(dp[s] != 0)
        {
            if(dp[s] == 1)
                return true;
            else
                return false;
        }
        
        //cout<<s<<endl;
        if(dictMap[s])
        {
            dp[s] = 1;
            return true;
        }
        
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            string prefix = s.substr(0, i+1);
            string suffix = s.substr(i+1, n-i-1);
            //cout<<prefix<<" "<<suffix<<endl;
            if(dictMap[prefix])
            {
                //cout<<"prefix found, calling recursion for suffix"<<endl;
                if(util(suffix))
                {
                    ans = true;
                }
            }
        }
        dp[s] = ans? 1:2;
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