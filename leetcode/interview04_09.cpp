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
    void cross(vector<int>& lseq, vector<int>& rseq, int i, int j, 
                              vector<vector<int>>& res, vector<int>& temp){
        if(i==lseq.size() && j==rseq.size()){
            res.emplace_back(temp);
            return;
        }
        if(i<lseq.size()){
            temp.push_back(lseq[i]);
            cross(lseq, rseq, i+1, j, res, temp);
            temp.pop_back();
        }
        if(j<rseq.size()){
            temp.push_back(rseq[j]);
            cross(lseq, rseq, i, j+1, res, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root==nullptr)
            return {{}};
        vector<vector<int>> l=BSTSequences(root->left);
        vector<vector<int>> r=BSTSequences(root->right);
        vector<vector<int>> res;
        vector<int> temp={root->val};
        for(vector<int>& lseq:l){
            for(vector<int>& rseq:r){
                cross(lseq, rseq, 0, 0, res, temp);
            }
        }
        return res;
    }
};


// 大佬写的回溯
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
    vector<vector<int>> res;
    vector<int> path;
    deque<TreeNode*> dq;
    void dfs(){
        if(dq.empty()){
            res.emplace_back(path);
            return;
        }
        for(int i=0,n=dq.size();i<n;i++){
            TreeNode* root=dq.front();
            dq.pop_front();
            path.push_back(root->val);
            if(root->left!=nullptr)
                dq.push_back(root->left);
            if(root->right!=nullptr)
                dq.push_back(root->right);
            dfs();
            path.pop_back();
            // 复原候选队列
            if(root->left!=nullptr)
                dq.pop_back();
            if(root->right!=nullptr)
                dq.pop_back();
            // 这样就让候选队列一直在循环移动，相当于每个元素都被选了一次
            // 类似于全排列
            dq.push_back(root);
        }
    }
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root==nullptr)
            return {{}};
        dq.push_back(root);
        dfs();
        return res;
    }
};