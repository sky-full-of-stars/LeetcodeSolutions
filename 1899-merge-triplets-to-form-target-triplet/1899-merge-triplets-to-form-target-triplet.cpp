class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
    {
        int f = target[0];
        int s = target[1];
        int t = target[2];
        bool _f= false, _s = false, _t = false;
        
        for(auto i : triplets)
        {
            if(i[0] == f and i[1]<=s and i[2]<=t)
            {
                _f = true;
            }
            if(i[1] == s and i[0]<=f and i[2]<=t)
            {
                _s = true;
            }
            if(i[2] == t and i[0]<=f and i[1]<=s)
            {
                _t = true;
            }
        }
        
        return (_f and _s and _t);
        
    }
};