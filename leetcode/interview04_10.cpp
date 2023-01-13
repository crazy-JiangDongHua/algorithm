/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一 递归
class Solution {
private:
    bool treeMatch(TreeNode* r1, TreeNode* r2){
        if(r1==nullptr && r2==nullptr)
            return true;
        else if(r1==nullptr || r2==nullptr)
            return false;
        return r1->val==r2->val && treeMatch(r1->left, r2->left) && treeMatch(r1->right, r2->right);
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr)
            return false;
        if(t1->val==t2->val && treeMatch(t1, t2))
            return true;
        return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};

// 方法二 先序遍历
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
    void getOrder(TreeNode* t, string& s){
        if(t==nullptr){
            s+="X ";
            return;
        }
        getOrder(t->left, s);
        s+=to_string(t->val);
        s+=" ";
        getOrder(t->right, s);
        return;
    }
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        string s1,s2;
        getOrder(t1, s1);
        getOrder(t2, s2);
        return s1.find(s2)!=string::npos;
    }
};