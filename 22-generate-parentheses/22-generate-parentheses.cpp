class Solution {
private:
    void generate(vector<string> &ans, string curString, int openRemaining, int closeRemaining)
    {   
        if(openRemaining == 0 and closeRemaining == 0)
        {
            ans.push_back(curString);
            return;
        }
        if(openRemaining > 0)
        {
            generate(ans, curString + "(" , openRemaining-1, closeRemaining);
        }
        if(closeRemaining > openRemaining)
        {
            generate(ans, curString + ")", openRemaining, closeRemaining-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        generate(ans,"", n, n);
        return ans;
    }
};