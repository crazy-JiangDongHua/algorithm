/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    void dfs(vector<vector<int>>& ans, vector<int>& res, TreeNode* root, int target, int sum){
        if(root==nullptr)
            return;
        sum+=root->val;
        res.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && sum==target){
            ans.emplace_back(res);
            res.pop_back();
            return;
        }
        dfs(ans, res, root->left, target, sum);
        dfs(ans, res, root->right, target, sum);
        res.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(ans, res, root, target, 0);
        return ans;
    }
};