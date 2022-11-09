class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        else if(root->left==nullptr && root->right==nullptr)
            return 1;
        else if(root->left!=nullptr && root->right!=nullptr)
            return min(minDepth(root->left), minDepth(root->right))+1;
        else if(root->left!=nullptr)
            return 1+minDepth(root->left);
        else
            return 1+minDepth(root->right);
    }
};


class Solution {
private:
    int minDepth(TreeNode* root, bool hasBrother){
        if(!root)return hasBrother?INT_MAX:0;
        return 1+min(minDepth(root->left, root->right!=nullptr), minDepth(root->right,root->left!=nullptr));
    }
public:
    int minDepth(TreeNode* root) {
        return minDepth(root, false);
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        if(root->left==nullptr && root->right==nullptr)
            return 1;
        return 1+min(!root->left?INT_MAX:minDepth(root->left), 
                     !root->right?INT_MAX:minDepth(root->right));
    }
};