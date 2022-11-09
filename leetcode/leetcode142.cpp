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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head, *fast=head;
        while(slow!=NULL && fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                return NULL;
            fast = fast->next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
