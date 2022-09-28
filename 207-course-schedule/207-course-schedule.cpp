class Solution 
{
private:
    bool dfs(int root, vector<int> &vis, vector<int> &dfsVis, vector<int> gp[])
    {
        vis[root] = 1;
        dfsVis[root] = 1;
        for(int child : gp[root])
        {
            if(!vis[child])
            {
                if(dfs(child, vis, dfsVis, gp))
                    return true;
            }
            else
            {
                if(dfsVis[child])
                    return true;
            }
        }
        dfsVis[root] = 0;
        return false;
    }
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> gp[numCourses];
        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        
        for(auto i: prerequisites)
        {
            gp[i[1]].push_back(i[0]);
        }
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, dfsVis, gp))
                    return false;
            }
        }
        return true;  
    }
};