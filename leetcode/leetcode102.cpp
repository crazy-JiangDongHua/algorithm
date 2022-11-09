class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            for(int i=0,n=q.size();i<n;i++){
                root=q.front();q.pop();
                ans.emplace_back(root->val);
                if(root->left!=nullptr)q.push(root->left);
                if(root->right!=nullptr)q.push(root->right);
            }
            res.emplace_back(ans);

        }
        return res;
    }
};