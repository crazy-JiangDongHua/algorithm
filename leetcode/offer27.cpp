/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 直接在原树上修改
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        TreeNode* orgLeft=mirrorTree(root->left);
        TreeNode* orgRight=mirrorTree(root->right);
        root->right=orgLeft;
        root->left=orgRight;
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 创建新树
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        TreeNode* newRoot=new TreeNode(root->val);
        TreeNode* newRight=mirrorTree(root->left);
        TreeNode* newLeft=mirrorTree(root->right);
        newRoot->left=newLeft;
        newRoot->right=newRight;
        return newRoot;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 迭代
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r=q.front();q.pop();
            if(r!=nullptr){
                swap(r->left, r->right);
                q.push(r->left);
                q.push(r->right);
            }
        }
        return root;
    }
};
