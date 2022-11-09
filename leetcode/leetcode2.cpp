/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode headnode(0,l1);
        ListNode* head = &headnode;
        int carry = 0;
        while(l1!=nullptr && l2!=nullptr)
        {
            head = head->next;
            head->val = l1->val+l2->val+carry;
            carry = head->val/10;
            head->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2!=nullptr)
        {
            head->next = l2;
        }
        while(head->next!=nullptr)
        {
            head = head->next;
            head->val = head->val+carry;
            carry = head->val/10;
            head->val %= 10;
        }
        while(carry!=0)
        {
            head->next = new ListNode(carry%10, nullptr);
            head=head->next;
            carry/=10;
        }
        return headnode.next;
    }
};
