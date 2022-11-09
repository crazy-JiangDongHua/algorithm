// 递归写法
class Solution {
private:
    vector<int> res;
    // 避免每次返回都要复制vector浪费时间
    void pre(TreeNode* root){
        if(root==nullptr)
            return;
        res.push_back(root->val);
        if(root->left!=nullptr)preorderTraversal(root->left);
        if(root->right!=nullptr)preorderTraversal(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return res;
    }
};


// 迭代写法1
class Solution {
private:
    vector<int> res;
    stack<TreeNode*> s;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)
            return res;
        s.push(root);
        while(!s.empty()){
            root=s.top();s.pop();
            res.push_back(root->val);
            if(root->right!=nullptr)s.push(root->right);
            if(root->left!=nullptr)s.push(root->left);
        }
        return res;
    }
};



//迭代写法2 最快！！！可能是因为不是所有的元素都需要入栈，常系数就小了
class Solution {
private:
    vector<int> res;
    stack<TreeNode*> s;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        while(true){
            while(root!=nullptr){
                res.push_back(root->val);
                if(root->right!=nullptr)s.push(root->right);
                root=root->left;
            }
            if(s.empty())break;
            //转向右子树
            root=s.top();s.pop();
        }
        return res;
    }
};

// 迭代写法3 mirros遍历
class Solution {
private:
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)return res;
        TreeNode* mostRight;//左子树中最右结点
        while(root!=nullptr){
            mostRight=root->left;
            if(mostRight==nullptr){//没有左子树
                res.push_back(root->val);
                root=root->right;
            }else{
                while(mostRight->right!=nullptr && mostRight->right!=root){
                    mostRight=mostRight->right;
                }
                if(mostRight->right==nullptr){
                    mostRight->right=root;
                    res.push_back(root->val);
                    root=root->left;
                }else{
                    mostRight->right=nullptr;
                    root=root->right;
                }
            }
        }
        return res;
    }
};
