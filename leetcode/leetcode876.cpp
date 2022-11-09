class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head, *slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return fast->next!=nullptr?slow->next:slow;
    }
};