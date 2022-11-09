class Solution {
private:
    bool isValidBST(TreeNode* root, long lower, long upper){
        if(root==nullptr)return true;
        return lower<root->val && root->val<upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

};