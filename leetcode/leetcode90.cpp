// 枚举每个元素出现的次数
class Solution {
private:
    void dfs(unordered_map<int ,int>& ht, unordered_map<int ,int>::iterator it, vector<int>& res, vector<vector<int>>& ans){
        if(it==ht.end()){
            ans.emplace_back(res);
            return;
        }
        dfs(ht, next(it), res, ans);
        for(int j=1,n=(*it).second;j<=n;j++){
            res.push_back((*it).first);
            dfs(ht, next(it), res, ans);
        }
        for(int j=1,n=(*it).second;j<=n;j++){
            res.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int ,int> ht;
        for(int& num:nums){
            ht[num]+=1;
        }
        vector<int> res;
        vector<vector<int>> ans;
        dfs(ht, ht.begin(), res, ans);
        return ans;
    }
};

// 先排序，不取和前面元素相同且前面元素没选的元素
class Solution {
private:
    void dfs(bool preChoose, int i, vector<int>& nums, vector<int>& res, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.emplace_back(res);
            return;
        }
        dfs(false, i+1, nums, res, ans);
        if(!(!preChoose && i>0 && nums[i]==nums[i-1])){
            res.push_back(nums[i]);
            dfs(true, i+1, nums, res, ans);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<vector<int>> ans;
        dfs(false, 0, nums, res, ans);
        return ans;
    }
};