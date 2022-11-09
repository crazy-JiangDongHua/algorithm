// 方法一 优先级队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<k;i++)
            pq.emplace(nums[i], i);
        vector<int> res;
        res.emplace_back(pq.top().first);
        int n=nums.size();
        for(int i=k;i<n;i++){
            while(!pq.empty() && pq.top().second<=i-k)
                pq.pop();
            pq.emplace(nums[i], i);
            res.emplace_back(pq.top().first);
        }
        return res;
    }
};

//方法二 单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n=nums.size();
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> res;
        res.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};