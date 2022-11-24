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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=nullptr)
            q.push(root);
        vector<int> ans;
        while(!q.empty()){
            root=q.front();q.pop();
            ans.push_back(root->val);
            if(root->left!=nullptr)
                q.push(root->left);
            if(root->right!=nullptr)
                q.push(root->right);
        }
        return ans;
    }
};