class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode dummy(-200,head), *header=&dummy;
        for(ListNode *pre=head, *cur=head->next;cur!=nullptr;cur=pre==nullptr?nullptr:pre->next){
            if(pre->val==cur->val){
                while(cur!=nullptr && pre->val==cur->val){
                    cur=cur->next;
                }
                header->next=cur;
                while(pre!=cur){
                    ListNode* tmp=pre->next;
                    delete pre;
                    pre=tmp;
                }
            }else{
                header=pre;
                pre=cur;
            }
        }
        return dummy.next;
    }
};