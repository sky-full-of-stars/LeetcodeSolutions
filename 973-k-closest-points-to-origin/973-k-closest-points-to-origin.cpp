typedef pair<double,vector<int>> type;

class Solution 
{
    
private:
    int square(int num)
    {
        return num*num;
    }
    double getDistance(int x1, int y1, int x2, int y2)
    {
        return sqrt( square((x1-x2)) + square((y1-y2)) );
    }
    
public:
    priority_queue<type, vector<type>> mxHeap;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> kClosestPoints;
        
        for(vector<int> point: points)
        {
            double distance = getDistance(point[0], point[1], 0, 0);
            mxHeap.push({distance, point});
            if(mxHeap.size() > k)
            {
                mxHeap.pop();
            }
        }
        
        while(!mxHeap.empty())
        {
            kClosestPoints.push_back(mxHeap.top().second);
            mxHeap.pop();
        }
        
        return kClosestPoints;
    }
};
