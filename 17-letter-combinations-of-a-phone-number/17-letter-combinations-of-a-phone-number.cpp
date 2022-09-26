class Solution {
private:
    void getLetters(int idx, string str, string &digits)
    {
        if(idx == sz and str.size()>0)
        {
            ans.push_back(str);
        }
        for(char letter: comb[digits[idx]])
        {
            getLetters(idx+1, str+letter, digits);
        }
    }
    
public:
    int sz;
    vector<string> ans;
    map<char, vector<char>> comb;
    vector<string> letterCombinations(string digits)
    {
        sz = digits.length();
        
        comb['2'] = {'a', 'b', 'c'};
        comb['3'] = {'d', 'e', 'f'};
        comb['4'] = {'g', 'h', 'i'};
        comb['5'] = {'j', 'k', 'l'};
        comb['6'] = {'m', 'n', 'o'};
        comb['7'] = {'p', 'q', 'r', 's'};
        comb['8'] = {'t', 'u', 'v'};
        comb['9'] = {'w', 'x', 'y', 'z'};
        
        int idx = 0;
        getLetters(idx, "", digits);
        
        return ans;
    }
};