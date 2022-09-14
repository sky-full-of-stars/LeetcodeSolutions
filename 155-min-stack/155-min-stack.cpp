class MinStack {

private:
    stack<int> s;
    stack<int> minStk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minStk.empty() or val <= minStk.top())
        {
            minStk.push(val);
        }
    }
    
    void pop() {
        if(!s.empty())
        {
            if(!minStk.empty() and s.top() == minStk.top())
                minStk.pop();
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty())
            return s.top();
        return -1;
    }
    
    int getMin() {
        if(!minStk.empty())
            return minStk.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */