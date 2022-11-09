// bfs
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        TreeNode *left=root->left, *right=root->right;
        queue<TreeNode*> ql, qr;
        ql.push(left);
        qr.push(right);
        while(!qr.empty() && !ql.empty()){
            left=ql.front();ql.pop();
            right=qr.front();qr.pop();
            if(left==nullptr && right==nullptr)continue;
            else if(left==nullptr || right==nullptr)return false;
            else if(left->val!=right->val)return false;
            ql.push(left->left);ql.push(left->right);
            qr.push(right->right);qr.push(right->left);
        }
        return true;
    }
};

//dfs
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        else return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left==nullptr && right==nullptr)return true;
        else if(left==nullptr || right==nullptr)return false;
        else return left->val==right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};