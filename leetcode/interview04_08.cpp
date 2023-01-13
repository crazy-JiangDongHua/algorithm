/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 方法一，搜索第一个处于二者之间的节点
class Solution {
private:
    bool cover(TreeNode* root, TreeNode* p){
        if(root==nullptr)
            return false;
        if(root->val==p->val)
            return true;
        return cover(root->left, p) || cover(root->right, p);
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        // 如果root是p，那么q一定在p的子树中，所以返回p
        // 其实这里root一定不会是nullptr
        if(root==nullptr || root==p || root==q)
            return root;
        bool pInLeft=cover(root->left, p);
        bool qInLeft=cover(root->left, q);
        // 第一个分叉点，如果是二叉搜索树就可以比大小，这里只能爆搜
        if(pInLeft!=qInLeft)
            return root;
        TreeNode* child=pInLeft?root->left:root->right;
        return helper(child, p, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果有节点不在树中，返回nullptr
        if(!cover(root, p) || !cover(root, q))
            return nullptr;
        return helper(root, p, q);
    }
};

// 方法二 自底向上递归
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
    struct Result{
        TreeNode* node;
        bool isAnswer;
        Result(TreeNode* n=nullptr, bool flag=false):node(n),isAnswer(flag){};
    };
    Result helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr)
            return Result();
        Result l=helper(root->left, p, q);
        // 子树中找到最低祖先
        if(l.isAnswer)
            return l;
        Result r=helper(root->right, p, q);
        if(r.isAnswer)
            return r;
        // 子树中没找到最低祖先，但是root就是最低祖先
        if(l.node!=nullptr && r.node!=nullptr)
            return Result(root, true);
        // l和r至少有一个为nullptr
        else if(root->val==p->val || root->val==q->val){
            // 包含两种情况
            // 1. 另一个节点不再树中
            // 2. 另一个节点不再当前子树中
            if(l.node==nullptr && r.node==nullptr)
                return Result(root, false);
            // 一个节点是另外一个节点的祖先
            return Result(root, true);
        }
        else
            return l.node!=nullptr?l:r;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Result r=helper(root, p, q);
        // 区分一个节点是另外一个节点的祖先的情况和一个节点不再树中的情况
        if(!r.isAnswer)
            return nullptr;
        return r.node;
    }
};

// 更精简的写法
class Solution {
private:
    TreeNode* ans;
    // 返回root是否至少包含p或q中的一个
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr)
            return false;
        bool l=helper(root->left, p, q);
        bool r=helper(root->right, p, q);
        if((l&&r) || (root->val==p->val||root->val==q->val) && (l||r))
            ans=root;
        return l||r||root->val==p->val||root->val==q->val;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=nullptr;
        helper(root, p, q);
        return ans;
    }
};