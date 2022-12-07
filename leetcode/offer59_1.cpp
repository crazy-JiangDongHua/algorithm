// 方法1 标准化实现QueueWithMax
class QueueWithMax{
private:
    queue<int> q;
    deque<int> maxq;
public:
    void push(int v){
        q.push(v);
        while(!maxq.empty() && v>maxq.back()){
            maxq.pop_back();
        }
        maxq.push_back(v);
    }
    int pop(){
        if(q.empty())
            throw exception();
        int v=q.front();
        q.pop();
        if(v==maxq.front())
            maxq.pop_front();
        return v;
    }
    int max(){
        if(q.empty())
            throw exception();
        return maxq.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k<=0 || nums.size()<k)
            throw exception();
        int i=0;
        QueueWithMax q;
        for(;i<k;i++)
            q.push(nums[i]);
        vector<int> ans;
        ans.push_back(q.max());
        for(int n=nums.size();i<n;i++){
            q.push(nums[i]);
            q.pop();
            ans.push_back(q.max());
        }
        return ans;
    }
};

// 只用deque存index，限于本题省内存
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k<=0 || nums.size()<k)
            throw exception();
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);
        for(int i=k, n=nums.size();i<n;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            while(dq.front()<=i-k)
                dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};