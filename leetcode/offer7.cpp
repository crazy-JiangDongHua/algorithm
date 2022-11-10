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
    TreeNode* subBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preL, int preR, int inL, int inR){
        if(preL==preR){
            if(inL!=inR)
                throw std::exception();
            else
                return nullptr;
        }

        TreeNode* root=new TreeNode(preorder[preL]);
        int id=inL;
        for(;id<inR;id++)
            if(inorder[id]==root->val)
                break;
        if(id==inR)
            throw std::exception();
        int lenL=id-inL;
        root->left=subBuildTree(preorder, inorder, preL+1, preL+1+lenL, inL, id);
        root->right=subBuildTree(preorder, inorder, preL+1+lenL, preR, id+1, inR);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()){
            throw std::exception();
        }
        int n=preorder.size();
        return subBuildTree(preorder, inorder, 0, n, 0, n);
    }
};