/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool dfs(vector<TreeNode*>& res, TreeNode* root, TreeNode* target){
        if(root==nullptr)
            return false;
        res.push_back(root);
        if(root==target){
            return true;
        }
        if(dfs(res, root->left, target))
            return true;
        if(dfs(res, root->right, target))
            return true;
        res.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || p==nullptr || q==nullptr)
            return nullptr;
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        dfs(p_path, root, p);
        dfs(q_path, root, q);
        TreeNode* ans=nullptr;
        int i=0;
        while(i<p_path.size()&&i<q_path.size()&&p_path[i]==q_path[i]){
            ans=p_path[i++];
        }
        return ans;
    }
};