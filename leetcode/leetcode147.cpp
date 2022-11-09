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
    ListNode* insertionSortList(ListNode* head) {
        ListNode prednode = ListNode(INT_MIN);
        ListNode* lastsort = &prednode;
        while(head!=nullptr)
        {
            if(lastsort->val <= head->val)
            {
                lastsort->next = head;
                lastsort = head;
                head = head->next;
                lastsort->next = nullptr;
                continue;
            }
            ListNode* pred = &prednode;
            while(pred->next!=nullptr && pred->next->val<=head->val)
                pred = pred->next;
            ListNode* tmp = head->next;
            head->next = pred->next;
            pred->next = head;
            head = tmp;
        }
        return prednode.next;
    }
};
