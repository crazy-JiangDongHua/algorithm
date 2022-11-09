// 分隔链表
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lo_head, hi_head;
        ListNode *lo=&lo_head, *hi=&hi_head;
        while(head!=nullptr){
            if(head->val<x){
                lo->next = head;
                lo = lo->next;
            }else{
                hi->next = head;
                hi = hi->next;
            }
            head=head->next;
        }
        lo->next = hi_head.next;
        hi->next = nullptr;
        return lo_head.next;
    }
};