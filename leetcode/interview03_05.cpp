class SortedStack {
private:
    stack<int> s1, s2;
public:
    SortedStack() {
    }
    
    void push(int val) {
        while(!s2.empty() && val>s2.top()){
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(val);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    void pop() {
        // if(s2.empty())
        //     throw exception();
        if(!isEmpty())
            s2.pop();
    }
    
    int peek() {
        if(s2.empty())
            return -1;
        return s2.top();
    }
    
    bool isEmpty() {
        return s2.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */