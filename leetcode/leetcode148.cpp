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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        ListNode* list1 = sortList(slow->next);
        fast->next = nullptr;
        ListNode* list2 = sortList(head);
        // merge two sort list
        ListNode prednode = ListNode(-1);
        ListNode* pred = &prednode;
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val <= list2->val)
            {
                pred->next = list1;
                list1 = list1->next;
            }
            else
            {
                pred->next = list2;
                list2 = list2->next;
            }
            pred = pred->next;
        }
        pred->next = list1==nullptr?list2:list1;
        return prednode.next;
    }
};
