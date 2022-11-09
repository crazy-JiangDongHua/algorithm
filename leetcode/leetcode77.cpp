class Solution {
private:
    void dfs(int i, int k, int n, vector<int>& res, vector<vector<int>>& ans){
        if(res.size()==k){
            ans.emplace_back(res);
            return;
        }
        if(i>n)return;
        dfs(i+1, k, n, res, ans);
        res.push_back(i);
        dfs(i+1, k, n, res, ans);
        res.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        vector<vector<int>> ans;
        dfs(1, k, n, res, ans);
        return ans;
    }
};