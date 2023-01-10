class MinStack {
private:
    stack<int> s, mins;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty() || x<=mins.top()){
            mins.push(x);
        }
    }
    
    void pop() {
        if(s.empty())
            throw exception();
        if(s.top()==mins.top())
            mins.pop();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            throw exception();
        return s.top();
    }
    
    int getMin() {
        if(s.empty())
            throw exception();
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */