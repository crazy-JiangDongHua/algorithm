class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        Node* cur=root;
        while(cur){
            Node dummy, *header=&dummy;
            for(;cur;cur=cur->next){
                if(cur->left){
                    header->next=cur->left;
                    header=cur->left;
                }
                if(cur->right){
                    header->next=cur->right;
                    header=cur->right;
                }
            }
            cur=dummy.next;
        }
        return root;
    }
};