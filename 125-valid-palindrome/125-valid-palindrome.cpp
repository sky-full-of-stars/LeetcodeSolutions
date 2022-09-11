class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n= s.length();
        int lo=0; 
        int hi= n-1;
        while(lo < hi)
        {
            if(!isalpha(s[lo]) and !isdigit(s[lo]))
            {
                lo++; continue;
            }
            if(!isalpha(s[hi]) and !isdigit(s[hi]))
            {
                hi--; continue;
            }
            if(tolower(s[lo])==tolower(s[hi]))
            {
                lo++, hi--;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};