// 排序去重
class Solution {
private:
    void dfs(bool preChoose, int i, int sum, int target, vector<int>& candidates, vector<int>& res, vector<vector<int>>& ans){
        if(sum==target){
            ans.emplace_back(res);
            return;
        }
        if(i==candidates.size() || sum>target)return;
        // 不拿第i个数
        dfs(false, i+1, sum, target, candidates, res, ans);
        // 拿第i个数
        if(!(!preChoose && i>0 && candidates[i-1]==candidates[i])){
            res.push_back(candidates[i]);
            dfs(true, i+1, sum+candidates[i], target, candidates, res, ans);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先大后小，那么很多数在后面就很难取很多次，相当于剪枝
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> ans;
        vector<int> res;
        dfs(false, 0, 0, target, candidates, res, ans);
        return ans;
    }
};


// 统计频率 遍历出现次数
class Solution {
private:
    vector<vector<int>> res;
    vector<int> ans;
    vector<pair<int,int>> freq;

    void dfs(int i, int sum, int target){
        if(sum==target){
            res.emplace_back(ans);
            return;
        }
        if(i==freq.size() || sum>target)return;
        // 不拿第i个数
        dfs(i+1,sum,target);
        // 拿第i个数n次, i加表示不可以重复取
        for(int n=1;n<=freq[i].second;n++){
            ans.emplace_back(freq[i].first);
            dfs(i+1, sum+freq[i].first*n, target);
        }
        for(int n=1;n<=freq[i].second;n++)
            ans.pop_back();
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先小后大，那么大数在后面就很难取很多次，相当于剪枝
        sort(candidates.begin(),candidates.end(), greater<int>());
        for(int& k:candidates){
            if(!freq.empty() && freq.back().first==k){
                freq.back().second++;
            }else{
                freq.emplace_back(k, 1);
            }
        }
        dfs(0, 0, target);
        return res;
    }
};