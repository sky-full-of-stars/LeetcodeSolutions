class Solution {
private:
    long long doOperation(long long lhs, long long rhs, char operation)
    {
        switch(operation)
        {
            case '+' :
                return lhs+rhs;
            case '-' :
                return lhs-rhs;
            case '*' :
                return lhs*rhs;
            case '/' :
                return lhs/rhs;
            default:
                return 0;
        }
    }
    bool isNumber(string s)
    {
        try
        {
           int n = stoi(s); 
           return true;
        }
        catch(exception e) 
        {    
            return false;
        }
    }
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> s;
        for(auto i: tokens)
        {
            string cur = i;
            if(isNumber(cur))
            {
                s.push(cur);
            }
            else
            {
                char operation = cur[0];
                long long rhs = stoll(s.top()); s.pop();
                long long lhs= stoll(s.top()); s.pop();
                int result = doOperation(lhs,rhs,operation);
                s.push(to_string(result));
            }
        }
        return stoi(s.top());
    }
};