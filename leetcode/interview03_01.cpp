class TripleInOne {
private:
    vector<int> array;
    vector<int> size;
    int stackSize;
    int topIndex(int stackNum){
        return stackNum*stackSize+size[stackNum]-1;
    }
public:
    TripleInOne(int stackSize) {
        array.assign(3*stackSize, 0);
        size.assign(3, 0);
        this->stackSize=stackSize;
    }
    
    void push(int stackNum, int value) {
        if(size[stackNum]<stackSize){
            size[stackNum]++;
            array[topIndex(stackNum)]=value;
        }
    }
    
    int pop(int stackNum) {
        if(size[stackNum]==0)
            return -1;
        int ans=array[topIndex(stackNum)];
        size[stackNum]--;
        return ans;
    }
    
    int peek(int stackNum) {
        if(size[stackNum]==0)
            return -1;
        return array[topIndex(stackNum)];
    }
    
    bool isEmpty(int stackNum) {
        return size[stackNum]==0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */