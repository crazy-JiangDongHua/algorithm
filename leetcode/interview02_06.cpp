/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法一 反转链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 反转链表，同时记录长度
        int len=0;
        ListNode dummy(-1);
        ListNode *temp, *p1=head;
        while(p1!=nullptr){
            temp=new ListNode(p1->val);
            temp->next=dummy.next;
            dummy.next=temp;
            p1=p1->next;
            len++;
        }
        p1=head;
        // 比较一般的元素
        ListNode* p2=dummy.next;
        for(int i=0;i<len/2;i++){
            if(p1->val!=p2->val)
                return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};

// 方法二 栈
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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode *slow=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            s.push(slow);
            slow=slow->next;
            fast=fast->next->next;
        }
        // 奇数节点的情况，跳过中间节点
        if(fast!=nullptr)
            slow=slow->next;
        while(slow!=nullptr){
            if(slow->val!=s.top()->val)
                return false;
            slow=slow->next;
            s.pop();
        }
        return true;
    }
};