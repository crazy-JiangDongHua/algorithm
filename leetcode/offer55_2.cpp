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
    int maxDepth(TreeNode* root){
        if(root==nullptr)
            return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        if(l>=0 && r>=0 && abs(l-r)<=1){
                return max(l,r)+1;
        }
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root)>=0; 
    }
};