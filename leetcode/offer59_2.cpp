class MaxQueue {
private:
    queue<int> q;
    deque<int> maxq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(maxq.empty())
            return -1;
        return maxq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!maxq.empty() && value>maxq.back()){
            maxq.pop_back();
        }
        maxq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int v=q.front();
        q.pop();
        if(v==maxq.front())
            maxq.pop_front();
        return v;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */