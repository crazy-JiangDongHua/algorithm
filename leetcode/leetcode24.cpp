class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head), *p=&dummy;
        while(p->next!=nullptr && p->next->next!=nullptr){
            ListNode *tmp = p->next->next;
            p->next->next = tmp->next;
            tmp->next=p->next;
            p->next=tmp;
            p=p->next->next;
        }
        return dummy.next;
    }
};