class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,head),*pre=&dummy,*last=head;
        int i;
        while(last!=nullptr){
            for(i=0;i<k && last!=nullptr;i++){
                last=last->next;
            }
            if(i<k)break;
            for(i=1;i<k;i++){
                ListNode* tmp=head->next;
                head->next=tmp->next;
                tmp->next=pre->next;
                pre->next=tmp;
            }
            pre=head;head=last;
        }
        return dummy.next;
    }
};