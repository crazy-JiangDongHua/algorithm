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
        ListNode* last = head;
        while(k-->0)
        {
            last = last->next;
        }
        while(last!= NULL)
        {
            head = head->next;
            last = last->next;
        }
        return head;
    }
};
