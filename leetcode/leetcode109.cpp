class Solution {
private:
    TreeNode* gen(ListNode*& head, int lo, int hi){
        if(lo>=hi)return nullptr;
        int mi=(lo+hi)/2;
        TreeNode* root=new TreeNode();
        root->left=gen(head, lo, mi);
        root->val=head->val;
        head=head->next;
        root->right=gen(head, mi+1,hi);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int l=0;
        ListNode* p=head;
        while(p!=nullptr){
            l++;
            p=p->next;
        }
        return gen(head, 0, l);
    }
};