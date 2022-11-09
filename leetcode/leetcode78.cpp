// dfs
class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& res, vector<vector<int>>& ans, int i){
        if(i==nums.size()){
            ans.emplace_back(res);
            return;
        }
        dfs(nums, res, ans, i+1);
        res.push_back(nums[i]);
        dfs(nums, res, ans, i+1);
        res.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(nums, res, ans, 0);
        return ans;
    }
};


// 二进制数
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        for(int i=0, n=1<<nums.size();i<n;i++){
            res.clear();
            for(int j=0;j<nums.size();j++){
                if(((i>>j)&1)==1){
                    res.push_back(nums[j]);
                }
            }
            ans.emplace_back(res);
        }
        return ans;
    }
};