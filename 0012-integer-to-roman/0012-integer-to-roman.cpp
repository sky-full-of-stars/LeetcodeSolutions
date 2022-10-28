class Solution {
public:
    
    string intToRoman(int num) 
    {
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        
        for(int i=0; num> 0; i++)
        {
            int curVal = val[i];
            string curSymb = sym[i];
            
            int numOfOccurance = num/curVal;
            if(numOfOccurance > 0)
            {
                while(numOfOccurance --)
                    ans += curSymb;
                
                num = num % curVal;
            }
            
        }
        return ans;
    }
};