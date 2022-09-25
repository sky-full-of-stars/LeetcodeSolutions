class KthLargest 
{
    priority_queue <int, vector<int>, greater<int> > min_heap;
    int sz;
    
public:
    KthLargest(int k, vector<int>& nums) 
    {
        sz = k;
        for(int i: nums)
        {
           add(i);
        }
    }
    
    int add(int val) 
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
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */