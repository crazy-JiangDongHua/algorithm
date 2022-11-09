class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next == nullptr)return head;
        for(ListNode *pre=head, *cur=head->next;cur!=nullptr;cur=pre->next){
            if(pre->val == cur->val){
                pre->next = cur->next;
                delete cur;
            }else{
                pre = cur;
            }
        }
        return head;
    }
};