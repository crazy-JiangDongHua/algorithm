// morris
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x=nullptr, *y=nullptr, *pred=nullptr, *mostRight=nullptr;
        while(root!=nullptr){
            mostRight=root->left;
            if(mostRight!=nullptr){
                while(mostRight->right!=nullptr && mostRight->right!=root){
                    mostRight=mostRight->right;
                }
                if(mostRight->right==nullptr){
                    mostRight->right=root;
                    root=root->left;
                }else{
                    if(pred!=nullptr && pred->val>root->val){
                        y=root;
                        if(x==nullptr){
                            x=pred;
                        }
                    }
                    mostRight->right=nullptr;
                    pred=root;
                    root=root->right;
                }
            }else{
                if(pred!=nullptr && pred->val>root->val){
                    y=root;
                    if(x==nullptr){
                        x=pred;
                    }
                }
                pred=root;
                root=root->right;
            }
        }
        swap(x->val, y->val);
    }
};


// 方法2
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x=nullptr, *y=nullptr, *pred=nullptr, *mostRight=nullptr;
        stack<TreeNode* > s;
        while(true){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            if(s.empty())break;
            root=s.top();s.pop();
            if(pred!=nullptr && pred->val>root->val){
                y=root;
                if(x==nullptr)x=pred;
                else break;
            }
            pred=root;
            root=root->right;
        }
        swap(x->val, y->val);
    }
};