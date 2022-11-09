//递归
Solution {
private:
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)return res;
        if(root->left!=nullptr)postorderTraversal(root->left);
        if(root->right!=nullptr)postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
};

// 迭代1 双栈模拟递归
class Solution {
private:
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)return res;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();s1.pop();
            s2.push(root);
            if(root->left!=nullptr)postorderTraversal(root->left);
            if(root->right!=nullptr)postorderTraversal(root->right);
        }
        while(!s2.empty()){
            root=s2.top();s2.pop();
            res.push_back(root->val);
        }
        return res;
    }
};

// 迭代2
class Solution {
private:
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* pre=nullptr;
        while(true){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            if(s.empty())break;
            root=s.top();
            if(root->right!=nullptr && root->right!=pre){
                root=root->right;
            }else{
                res.push_back(root->val);
                pre=root;
                root=nullptr;
                s.pop();
            }
        }
        return res;
    }
};