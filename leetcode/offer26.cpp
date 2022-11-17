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
    bool isMatch(TreeNode* A, TreeNode* B){
        if(B==nullptr)
            return true;
        if(A==nullptr)
            return false;
        if(A->val!=B->val)
            return false;
        return isMatch(A->left, B->left)&&isMatch(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B==nullptr)
            return false;
        bool res=false;
        if(A->val==B->val){
            res=isMatch(A, B);
        }
        if(!res){
            res=isSubStructure(A->left, B);
        }
        if(!res){
            res=isSubStructure(A->right, B);
        }
        return res;
    }
};