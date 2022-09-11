class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int,int> cntIdx;
        for(int i: nums)
        {
            cntIdx[i]++;
        }
        set<pair<int,int>> inverseCntIdx;
        for(auto i: cntIdx)
        {
            inverseCntIdx.insert({i.second,i.first});
        }
        
        vector<int> ans;
        for(auto i=inverseCntIdx.rbegin(); i!=inverseCntIdx.rend(); i++)
        {
            //cout<<(*i).first<<" "<<(*i).second<<endl;
            if(k==0)
            {
                break;
            }
            ans.push_back((*i).second);
            k--;
        }
        return ans;
    }
};