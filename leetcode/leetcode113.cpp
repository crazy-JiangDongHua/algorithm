class Solution {
private:
    vector<vector<int>> res;
    vector<int> ans;
    void dfs(TreeNode* root, int targetSum){
        if(root==nullptr)return;
        ans.push_back(root->val);
        targetSum-=root->val;
        if(root->left==nullptr && root->right==nullptr && targetSum==0){
            res.emplace_back(ans);
            ans.pop_back();
            return;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        ans.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};