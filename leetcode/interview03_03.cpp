class StackOfPlates {
private:
    vector<stack<int>> stacks;
    int cap;
    
    bool isEmpty(){
        return stacks.empty();
    }

    bool isFull(){ // 最后一个stack满了
        return !stacks.empty() && stacks[stacks.size()-1].size()==cap;
    }

    bool isNeedExpand(){
        return isEmpty() || isFull();
    }
public:
    StackOfPlates(int cap) {
        this->cap=cap;
    }
    
    void push(int val) {
        if(cap==0)
            return;
        if(isNeedExpand())
            stacks.emplace_back(stack<int>());
        stacks[stacks.size()-1].push(val);
    }
    
    int pop() {
        return popAt(((int)stacks.size())-1);
    }
    
    int popAt(int index) {
        if(index>=stacks.size() || index<0)
            return -1;
        int ans=stacks[index].top();    
        stacks[index].pop();
        if(stacks[index].empty())
            stacks.erase(stacks.begin()+index);
        return ans;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */