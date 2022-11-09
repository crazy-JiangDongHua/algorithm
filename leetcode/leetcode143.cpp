class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return;

        ListNode h_dummy(0,head), *last=head;
        // split
        while(last->next!=nullptr && last->next->next!=nullptr){
            head=head->next;
            last=last->next->next;
        }
        last=head->next;
        head->next=nullptr;
        
        // reverse
        ListNode l_dummy(0,last);
        while(last->next!=nullptr){
            ListNode* tmp=last->next;
            last->next=tmp->next;
            tmp->next=l_dummy.next;
            l_dummy.next=tmp;
        }

        // merge head必然更多
        head=h_dummy.next;
        last=l_dummy.next;
        while(last!=nullptr){
            ListNode *tmp=last->next;
            last->next=head->next;
            head->next=last;
            head=head->next->next;
            last=tmp;
        }
        return;
    }
};