class Solution {
private:
    vector<string> allCombination;
    map<char,char> isMatch;
    void generateAllCombination(int n, string str)
    {
        if(n==0)
        {
            allCombination.push_back(str);
            return;
        }
        generateAllCombination(n-1, str +"(");
        generateAllCombination(n-1, str +")");
    }
    bool isOpen(char c)
    {
        return ( c == '(');
    }
    void init()
    {
        isMatch['('] = ')';
    }
    bool isValid(string str)
    {
        stack<char> s;
        init();
        int n = str.size();
        
        for(int i=0;i<n;i++)
        {
            char cur = str[i];
            if(isOpen(cur))
            {
                s.push(cur);
            }
            else 
            {
                if(s.empty())
                {
                    return false;
                }
                char top = s.top();
                if(isMatch[top] == cur)
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(!s.empty())
        {
            return false;
        }
        return true;
    }
    vector<string> filterValidOnes(vector<string> all)
    {
        vector<string> ans;
        for(string each: all)
            if(isValid(each))
                ans.push_back(each);
        return ans;
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        n = n*2;
        generateAllCombination(n-1, "(");
        return filterValidOnes(allCombination);
    }
};