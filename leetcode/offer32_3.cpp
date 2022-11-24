/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 简单reverse
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        bool flag=false;
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
            if(flag)
                reverse(res.begin(), res.end());
            ans.emplace_back(res);
            flag=!flag;
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 双栈模拟
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        bool flag=false;
        stack<TreeNode*> s1, s2;
        if(root!=nullptr)
            s1.push(root);
        while(!s1.empty()||!s2.empty()){
            res.clear();
            if(flag){
                for(int i=0, s=s2.size();i<s;i++){
                    root=s2.top();s2.pop();
                    if(root->right!=nullptr)
                        s1.push(root->right);
                    if(root->left!=nullptr)
                        s1.push(root->left);
                    res.push_back(root->val);
                }
            }
            else{
                for(int i=0, s=s1.size();i<s;i++){
                    root=s1.top();s1.pop();
                    if(root->left!=nullptr)
                        s2.push(root->left);
                    if(root->right!=nullptr)
                        s2.push(root->right);
                    res.push_back(root->val);
                }
            }
            ans.emplace_back(res);
            flag=!flag;
        }
        return ans;
    }
};