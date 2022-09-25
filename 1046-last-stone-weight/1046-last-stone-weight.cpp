class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> mxHeap;
        
        for(int i: stones)
            mxHeap.push(i);
        
        while(mxHeap.size()>1)
        {
            int x = mxHeap.top();
            mxHeap.pop();
            int y = mxHeap.top();
            mxHeap.pop();
            if(x<y) 
                swap(x,y);
            if(x>=y)
                mxHeap.push(x-y);
        }
        
        return mxHeap.top();
    }
};