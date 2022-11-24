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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        queue<TreeNode*> q;
        if(root!=nullptr)
            q.push(root);
        while(!q.empty()){
            res.clear();
            for(int i=0, s=q.size();i<s;i++){
                root=q.front();q.pop();
                res.push_back(root->val);
                if(root->left!=nullptr)
                    q.push(root->left);
                if(root->right!=nullptr)
                    q.push(root->right);
            }
            ans.emplace_back(res);
        }
        return ans;
    }
};