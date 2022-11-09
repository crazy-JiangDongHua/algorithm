// 用栈存储右结点
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode dummy, *header=&dummy;
        stack<TreeNode*> s;
        while(true){
            while(root!=nullptr){
                header->right=root;
                header=header->right;
                if(root->right!=nullptr)
                    s.push(root->right);
                root=root->left;
                header->left=nullptr;
            }
            if(s.empty())return;
            root=s.top();s.pop();
        }
    }
};

// 迭代2 morris改版
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode dummy, *header=&dummy;
        TreeNode *mostRight=nullptr;
        while(root!=nullptr){
            mostRight=root->left;
            if(mostRight!=nullptr){
                while(mostRight->right!=nullptr)
                    mostRight=mostRight->right;
                mostRight->right=root->right; //因为不是遍历，本身就要串起来，所以直接指向后继
                TreeNode* next=root->left;
                root->left=nullptr;
                root->right=next;
            }
            root=root->right;
        }
    }
};