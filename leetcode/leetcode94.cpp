//递归版本
class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)return res;
        if(root->left!=nullptr)inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right!=nullptr)inorderTraversal(root->right);
        return res;
    }
};


// 迭代1
class Solution {
private:
    vector<int> res;
    stack<TreeNode*> s;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        while(true){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            if(s.empty())break;
            root=s.top();s.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};

// 迭代2 morris
class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* mostRight=nullptr;
        while(root!=nullptr){
            mostRight=root->left;
            if(mostRight!=nullptr){
                while(mostRight->right!=nullptr && mostRight->right!=root)
                    mostRight=mostRight->right;
                if(mostRight->right==nullptr){
                    mostRight->right=root;
                    root=root->left;
                }else{
                    res.push_back(root->val);
                    mostRight->right=nullptr;
                    root=root->right;
                }
            }else{
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};