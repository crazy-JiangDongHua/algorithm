class MedianFinder {
private:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        // & 优先级低于 ==，一定要打括号
        if(((max_pq.size()+min_pq.size())&1)==0){
            if(!max_pq.empty() && num<max_pq.top()){
                max_pq.push(num);
                num=max_pq.top();
                max_pq.pop();
            }
            min_pq.push(num);
        }else{
            if(!min_pq.empty() && num>min_pq.top()){
                min_pq.push(num);
                num=min_pq.top();
                min_pq.pop();
            }
            max_pq.push(num);
        }
    }
    
    double findMedian() {
        if(max_pq.empty() && min_pq.empty())
            return 0.0;
        else if(((max_pq.size()+min_pq.size())&1)==0)
            return ((double)max_pq.top()+min_pq.top())/2;
        else{
            return min_pq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */