class Solution 
{
    bool generate(string soFar, int i, int j, int k, string &s1, string &s2, string &res, vector<vector<int>> &cache)
    {
        if(i == n and j == m and k == res.size())
        {
           if(soFar == res)
            return true;
        }
        if(i > n or j>m or k>res.size())
        {
            return false;
        }
        if(i<n and j<m and cache[i][j] != -1)
        {
            return cache[i][j];
        }
        
        //can pick char from either of strings
        if((i < n and s1[i] == res[k]) and (j < m and s2[j] == res[k]))
        {
            return cache[i][j] = (generate(soFar + s1[i], i+1, j, k+1, s1, s2, res, cache) or 
                                  generate(soFar + s2[j], i, j+1, k+1, s1, s2, res, cache) );
        }
        else if(i < n and s1[i] == res[k]) 
        {
            return generate(soFar + s1[i], i+1, j, k+1, s1, s2, res, cache);
        }
        else if(j < m and s2[j] == res[k])
        {
            return generate(soFar + s2[j], i, j+1, k+1, s1, s2, res, cache);
        }
        else
        {
            return cache[i][j] = false;
        }
    }
    
public:
    int n,m;
    bool isInterleave(string s1, string s2, string s3) 
    {
        n = s1.length();
        m = s2.length();
        
        if(n+m != s3.length())
            return false;
        
        vector<vector<int>> cache(n+1, vector<int>(m+1, -1));
        return generate("", 0, 0, 0, s1, s2, s3, cache);
    }
};