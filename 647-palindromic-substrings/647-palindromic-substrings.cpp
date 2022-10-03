class Solution 
{
private:
    //get max length of palindromic substring possible with string starting from l ending r, expanding outwards bidirectionaly
    int findRangeSubstring(int l, int r, string &s)
    {
        int ans = 0;
        while(l>=0 and r<n and s[l]==s[r])
        {
            ans = r-l+1;
            l--; 
            r++;
        }
        return ans;
    }
    //get num of combination of subset palindromes possible for this length
    int getPalindromesForALength(int n)
    {
        return (n+1)/2;
    }
public:
    int n;
    int countSubstrings(string s) 
    {
        n= s.length();
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            //odd length palindromes with ith character as middle
            int l=i, r=i;
            int len =findRangeSubstring(l, r, s);
            int combinations = getPalindromesForALength(len);
            ans += combinations;
            
            //even length palindromes with ith character as middle
            l=i, r = i+1;
            len = findRangeSubstring(l, r, s);
            combinations = getPalindromesForALength(len);
            ans += combinations;
        }
        
        return ans;
    }
};