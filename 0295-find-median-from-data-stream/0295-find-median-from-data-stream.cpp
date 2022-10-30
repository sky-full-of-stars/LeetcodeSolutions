class MedianFinder 
{
public:
    priority_queue<int, vector<int>> mxHeap;
    priority_queue<int, vector<int>, greater<int>> mnHeap;
    
    void rebalanceHeapSizes()
    {
        /*
            since we're rebalancing after every element, 
            single pop from mxHeap and push to mnHeap actually rebalances heaps.
        
            More convincing code would look something like below
            So we know, maximum allowed mxHeapSize is mnHeapSz + 1.
            if its more than that, any point then rebalnce
            if(mxHeap.size() + 2 == mnHeap.size())
            {
                mnHeap.push(mxHeap.top()); mxHeap.pop();
            }
        */
        if(mxHeap.size() > mnHeap.size() + 1)
        {
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }
        else if(mnHeap.size() > mxHeap.size())
        {
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
    }
    void addNum(int num) 
    {
        if(mxHeap.size()==0 or num < mxHeap.top())
        {
            mxHeap.push(num);
        }
        else
        {
            mnHeap.push(num);
        }

        rebalanceHeapSizes();  
    }
    
    double findMedian() 
    {
        if(mxHeap.size() > mnHeap.size())
            return mxHeap.top();
        else
            return (mxHeap.top() + mnHeap.top())/2.0;
    }
};
