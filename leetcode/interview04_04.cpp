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
    int checkHeight(TreeNode* root){
        if(root==nullptr)
            return 0;
        int lh=checkHeight(root->left);
        int rh=checkHeight(root->right);
        if(lh==-1 || rh==-1 || abs(lh-rh)>1)
            return -1;
        return max(lh, rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root)>=0;
    }
};