// 直接利用上一层构建好的next指针建立下一层的next指针
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        Node *mostLeft=root, *cur=mostLeft;
        while(mostLeft->left!=nullptr){
            while(cur!=nullptr){
                cur->left->next=cur->right;
                if(cur->next!=nullptr)
                    cur->right->next=cur->next->left;
                cur=cur->next;
            }
            mostLeft=mostLeft->left;
            cur=mostLeft;
        }
        return root;
    }
};

//层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        queue<Node*> q;
        q.push(root);
        Node *pre=nullptr,*cur=nullptr;
        while(!q.empty()){
            for(int i=0,n=q.size();i<n;i++){
                cur=q.front();q.pop();
                if(cur->left!=nullptr)q.push(cur->left);
                if(cur->right!=nullptr)q.push(cur->right);
                if(pre!=nullptr){
                    pre->next=cur;
                }
                pre=cur;
            }
            cur->next=nullptr;
            pre=nullptr;
        }
        return root;
    }
};