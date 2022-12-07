/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BadInputException : public exception{
private:
    int flag;
public:
    BadInputException(int f){
        flag=f;
    }
    const char* what() const throw(){
        if(flag==1)
            return "input empty tree";
        else if(flag==2)
            return "input k is less than or equal to 0";
        else if(flag==3)
            return "input k is greater than the size of input tree";
        else 
            return "unknow error";
    }
};

// 递归
class Solution {
private:
    TreeNode* midOrderTravel(TreeNode* root, int& k){
        TreeNode* res=nullptr;
        if(root->right!=nullptr)
            res=midOrderTravel(root->right, k);
        if(res==nullptr){
            if(k==1)
                res=root;
            k--;
        }
        if(res==nullptr && root->left!=nullptr)
            res=midOrderTravel(root->left, k);
        return res;
    }
public:
    int kthLargest(TreeNode* root, int k) {
        if(root==nullptr)
            throw BadInputException(1);
        if(k<=0)
            throw BadInputException(2);
        TreeNode* pk = midOrderTravel(root, k);
        if(pk==nullptr)
            throw BadInputException(3);
        return pk->val;
    }
};


// 迭代
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if(root==nullptr)
            throw BadInputException(1);
        if(k<=0)
            throw BadInputException(2);
        stack<TreeNode*> s;
        while(true){
            while(root!=nullptr){
                s.push(root);
                root=root->right;
            }
            if(s.empty())
                throw BadInputException(3); 
            root=s.top();
            s.pop();
            if(k==1){
                break;
            }else{
                k--;
            }
            root=root->left;
        }
        return root->val;
    }
};