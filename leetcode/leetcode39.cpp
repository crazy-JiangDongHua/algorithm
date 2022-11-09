class Solution {
private:
    vector<vector<int>> res;
    vector<int> ans;

    void dfs(int i, int sum, int target, vector<int>& candidates){
        if(sum==target){
            res.emplace_back(ans);
            return;
        }
        if(i==candidates.size() || sum>target)return;
        // 拿第i个数, i不加表示可以重复取
        ans.emplace_back(candidates[i]);
        dfs(i, sum+candidates[i], target, candidates);
        ans.pop_back();
        // 不拿第i个数
        dfs(i+1, sum, target, candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, target, candidates);
        return res;
    }
};