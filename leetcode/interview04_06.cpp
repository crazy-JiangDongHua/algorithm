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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans=nullptr;
        if(p->right!=nullptr){
            ans=p->right;
            while(ans->left!=nullptr)
                ans=ans->left;
        }else{
            while(root!=nullptr){
                if(root->val>p->val){
                    ans=root;
                    root=root->left;
                }else{// 等于情况下移到右指针停止查找
                    root=root->right;
                }
            }
        }
        return ans;
    }
};