class Solution
{
    
public:
    vector<int> partitionLabels(string str) 
    {
        set<char> s;
        vector<int> v;
        map<char, int> cnt;
        
        for(char c: str)
        {
            cnt[c]++;
        }
        
        int prev = 0, cur = 0;
        for(char c: str)
        {
            cur++;
            s.insert(c);
            cnt[c]--;
            if(cnt[c] == 0)
            {
                s.erase(c);
            }
            if(s.empty())
            {
                v.push_back(cur-prev);
                prev = cur;
            }
        }
        
        return v;
    }
};