typedef pair<int,int> pi;
class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {   
        vector<vector<pi>> gp(n+1);
        for(auto i: times)
        {
            int from = i[0];
            int to = i[1];
            int weight = i[2];
            gp[from].push_back({to, weight});
        }
        
        pi root = {k, 0};
        vector<int> dist(n+1, INT_MAX);
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0,k});
        dist[k] = 0;
        
        while(!pq.empty())
        {
            pi root = pq.top();
            int from = root.second;   
            pq.pop();
            
            for(auto edge : gp[from])
            {
                int to = edge.first;
                int weight = edge.second;
                
                if(dist[from] != INT_MAX and (dist[from] + weight)<dist[to] )
                {
                    dist[to] = dist[from] + weight;
                    pq.push({dist[from]+ weight, to});
                }
            }
        }

        int mxTime = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            int dis = dist[i];
            mxTime = max(dis, mxTime);
        }
        return (mxTime == INT_MAX)? -1 : mxTime;
    }
};
