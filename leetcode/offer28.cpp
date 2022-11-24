/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归
class Solution {
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr && root2==nullptr)
            return true;
        if(root1==nullptr || root2==nullptr)
            return false;
        if(root1->val!=root2->val)
            return false;
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1,q2;
        q1.push(root);
        q2.push(root);
        while(!q1.empty()&&!q2.empty()){
            TreeNode* r1=q1.front();q1.pop();
            TreeNode* r2=q2.front();q2.pop();
            if(r1==nullptr&&r2==nullptr)
                continue;
            else if(r1==nullptr||r2==nullptr)
                return false;
            else if(r1->val!=r2->val)
                return false;
            else{
                q1.push(r1->left);
                q1.push(r1->right);
                q2.push(r2->right);
                q2.push(r2->left);
            }
        }
        return true;
    }
};