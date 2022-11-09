class Solution {
private:
    int res=INT_MIN;
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;
        int l=max(dfs(root->left),0);
        int r=max(dfs(root->right),0);
        res=max(res,root->val+l+r);
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};