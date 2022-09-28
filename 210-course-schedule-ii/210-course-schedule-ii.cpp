class Solution 
{
private:
    bool dfs(int root, vector<int> &vis, vector<int> &dfsVis, vector<int> gp[], stack<int> &stk)
    {
        vis[root] = 1;
        dfsVis[root] = 1;
        for(int child : gp[root])
        {
            if(!vis[child])
            {
                if(dfs(child, vis, dfsVis, gp, stk))
                    return true;
            }
            else
            {
                if(dfsVis[child])
                    return true;
            }
        }
        dfsVis[root] = 0;
        stk.push(root);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> ans;
        stack<int> stk;
        vector<int> gp[numCourses];
        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        
        for(auto i: prerequisites)
        {
            gp[i[1]].push_back(i[0]);
        }
        /*
        single stack is enough to get job done, once a bunch of nodes(a,b,c,d) are done push to stk
        then next connected components can be processed and they can pushed to stack
        next bunch by bunch we can un stack elements
        think (1->2 3->4) to visualize
        */
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, dfsVis, gp, stk))
                {
                    return vector<int>();
                }
            }
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};