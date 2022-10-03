class Solution {

private:
    void getMaxStringInRange(int &l, int &r, string &ans, int &len, string &s)
    {
        while(l>=0 and r<n and s[l] == s[r])
        {
            int curlen = r-l+1;
            if(curlen > len)
            {
                len = curlen;
                ans = s.substr(l, curlen);
            }
            l--;
            r++;
        }
    }
    
public:
    int n;
    string longestPalindrome(string s)
    {
        string ans = "";
        int len = -1;
        n = s.length();
        
        for(int i=0; i<n; i++)
        {
            //consider this(every char) as middle char of palindrome.
            //lets expand outwards
            
            //this as centre, and finding odd length palindrome
            int l = i, r = i; //considering i,i as range not i-1 and i+1 to accomodate for single length palindrome
            getMaxStringInRange(l,r,ans,len,s);
            
            //this as middle node, and finding even length palindrome
            l = i, r = i+1;
            getMaxStringInRange(l,r,ans,len,s);
            
        }
        
        return ans;
    }
};