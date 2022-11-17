/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 方法1 直接模拟
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr, *cur=head, *next=nullptr;
        while(cur!=nullptr){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};

// 头插法
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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        ListNode *cur=head;
        while(cur!=nullptr){
            ListNode *tmp=cur;
            cur=cur->next;
            tmp->next=dummy.next;
            dummy.next=tmp;
        }
        return dummy.next;
    }
};