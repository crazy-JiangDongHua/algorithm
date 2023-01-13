/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一 中序遍历
class Solution {
private:
    bool isValidBST(TreeNode* root, TreeNode*& prev){
        if(root==nullptr){
            return true;
        }
        if(!isValidBST(root->left, prev))
            return false;
        // 只能处理无重复的二叉搜索树
        if(prev!=nullptr && root->val<=prev->val)
            return false;
        prev=root;
        return isValidBST(root->right, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        return isValidBST(root, prev);
    }
};

// 方法二 递归
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
    bool isValidBST(TreeNode* root, long min, long max){
        if(root==nullptr)
            return true;
        if(root->val<=min || root->val>=max)
            return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);  
    }
};