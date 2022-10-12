class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        int n = hand.size();
        
        if(n % groupSize != 0)
            return false;
        
        map<int,int> cnt;
        for(int i: hand)
            cnt[i]++;
        
        for(auto [k,v] : cnt)
        {
            int mnGrpVal = k;
            int mnCnt = v;
            
            if(mnCnt == 0)
                continue;
            
            for(int i=0;i<groupSize; i++)
            {
                if(cnt[mnGrpVal+i] >= mnCnt)
                {
                    cnt[mnGrpVal+i] -= mnCnt;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};