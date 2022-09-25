class Solution 
{
private:
    int addToHeap(int val) 
    {
        min_heap.push(val);
        
        //every time you cross k elements, eliminate lowest one
        if(min_heap.size() > sz)
        {
            min_heap.pop();
        }
        
        //in the end, you'll have k largest elements with kth largest on top
        return min_heap.top();
    }
    
public:
    
    priority_queue <int, vector<int>, greater<int> > min_heap;
    int sz;
    
    int findKthLargest(vector<int>& nums, int k)
    {
        sz = k;
        
        for(int i: nums)
        {
           addToHeap(i);
        }
        return min_heap.top();
    }
};