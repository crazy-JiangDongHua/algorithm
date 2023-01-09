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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)
            return nullptr;
        ListNode *tail=head, *cur=head->next, *temp;
        head->next=tail->next=nullptr;
        while(cur!=nullptr){
            temp=cur->next;
            if(cur->val<x){
                cur->next=head;
                head=cur;
            }else{
                tail->next=cur;
                tail=cur;
            }
            cur=temp;
        }
        tail->next=nullptr;
        return head;
    }
};