/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==nullptr || k==0)
            return nullptr;
        ListNode* fast=head;
        for(int i=1;i<k;i++){
            if(fast->next!=nullptr)
                fast=fast->next;
            else
                return nullptr;
        }
        ListNode* slow=head;
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};