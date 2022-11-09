class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode dummy(0,head),*header=&dummy;
        while(header->next!=nullptr){
            header=header->next;
            n++;
        }
        if(n==0||k==0)return head;
        k = n-k%n;
        header->next=head;
        while(k--)header=header->next;
        dummy.next=header->next;
        header->next=nullptr;
        return dummy.next;
    }
};