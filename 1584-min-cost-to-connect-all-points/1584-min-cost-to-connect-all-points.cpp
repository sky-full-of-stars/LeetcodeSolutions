typedef pair<int,int> point;
typedef pair<int, point> type; //<weight, <from, to>>

class Solution 
{
private:
    int getDistanceBn2Points(point x, point y)
    {
        return getManhattenDist(x.first, x.second, y.first, y.second);
    }
    double getManhattenDist(int x1, int y1, int x2, int y2)
    {
        return (abs(x1-x2) + abs(y1-y2));
    }
    
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int totalMinWeight = 0;
        
        point to = {points[0][0], points[0][1]};
        
        map<point, bool> vis;
        
        priority_queue<type, vector<type>, greater<type>> minHeap;
        minHeap.push({0, to});
        
        while(!minHeap.empty())
        {
            type cur = minHeap.top();
            minHeap.pop();
            
            point to = cur.second;
            int weight = cur.first;
            
            if(vis[to])
                continue;
            
            vis[to] = true;
            totalMinWeight += weight;
            
            for(auto each: points)
            {
                point child = {each[0], each[1]};
                if(!vis[child])
                {
                    double dist = getDistanceBn2Points(to, child);
                    minHeap.push({dist,child});
                }
            }
        }
    
        return totalMinWeight;
    }
};