// 树状数组
class NumArray {
private:
    vector<int> c;
    vector<int> nums=nums;
    int lowbit(int x){return x&(-x);}
    void updateDelta(int x, int v){
        for(int i=x;i<c.size();i+=lowbit(i)){
            c[i]+=v;
        }
    }
    int getSum(int x){
        int sum=0;
        for(int i=x;i>0;i-=lowbit(i)){
            sum+=c[i];
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        c.assign(nums.size()+1, 0);
        this->nums=nums;
        for(int i=0;i<nums.size();i++){
            updateDelta(i+1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        updateDelta(index+1, val-nums[index]);
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        return getSum(right+1)-getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// 分块思想
class NumArray {
private:
    vector<int> block; //存储每个块的和
    int size;
    vector<int> nums;
    int getSum(int index){
        int sum=0;
        for(int i=0;i<index/size;i++)
            sum+=block[i];
        for(int i=index/size*size;i<=index;i++)
            sum+=nums[i];
        return sum;
    }
public:
    NumArray(vector<int>& nums):nums(nums){
        size=(int)sqrt(nums.size());
        block.assign(nums.size()/size+1, 0);
        for(int i=0;i<nums.size();i++){
            block[i/size]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        block[index/size]+=val-nums[index];
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        return getSum(right)-getSum(left)+nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */