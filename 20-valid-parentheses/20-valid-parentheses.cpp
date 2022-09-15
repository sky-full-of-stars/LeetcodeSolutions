class Solution {
private:
    map<char,char> isMatch;
    bool isOpen(char c)
    {
        return ( c == '(' or c == '{' or c == '[' );
    }
    void init()
    {
        isMatch['('] = ')';
        isMatch['{'] = '}';
        isMatch['['] = ']';
    }
public:
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
};