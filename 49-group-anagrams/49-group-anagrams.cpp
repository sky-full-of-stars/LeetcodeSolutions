class Solution 
{
    private:
        map<char,int> getCharCountMp(string s)
        {
            map<char, int> mp;
            for(char c: s)
            {
                mp[c]++;
            }
            return mp;
        }
        bool isAnagram(string s,map<char,int> mp)
        {
            for(char c: s)
            {
                mp[c]--;
            }
            for(auto i: mp)
            {
                if(i.second != 0)
                {
                    return false;
                }
            }
            return true;
        }
    
    public:  
        //O(n^2)
        vector<vector<string>> groupAnagramsBrute(vector<string>& str)
        {
            const int n = str.size();
            vector<vector<string>> ans;

            vector<int> vis(n,0);
            for(int i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    vector<string> subList;
                    subList.push_back(str[i]);
                    vis[i] = 1;
                    map<char,int> charMp = getCharCountMp(str[i]);
                    for(int j= i+1; j<n; j++)
                    {
                        if(isAnagram(str[j], charMp))
                        {
                            subList.push_back(str[j]);
                            vis[j] = 1;
                        }
                    }
                    ans.push_back(subList);
                }
            }
            return ans;
        }
    
        //efficient: o(n log2 n) : n = str.size()
        vector<vector<string>> groupAnagrams(vector<string>& str)
        {
            const int n = str.size();
            vector<vector<string>> ans;
            
            vector<pair<string,string>> strPair;
            for(string i: str)
            {
                string _i = i;
                sort(i.begin(), i.end());
                strPair.push_back({i,_i});
            }
            sort(strPair.begin(), strPair.end());
            
            for(int i=0;i<n;)
            {
                vector<string> subList;
                subList.push_back(strPair[i].second);
                int j = i+1;
                while(j<n and strPair[j].first == strPair[i].first)
                {
                    subList.push_back(strPair[j].second);
                    j++;
                }
                ans.push_back(subList);
                i = j;
            }
            return ans;
        }
};