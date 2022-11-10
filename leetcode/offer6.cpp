// 栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        while(head!=nullptr){
            s.push(head->val);
            head=head->next;
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

// 反转链表
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
    vector<int> reversePrint(ListNode* head) {
        if(head==nullptr){
            return {};
        }else if(head->next==nullptr){
            return {head->val};
        }
        ListNode *pre=head, *cur=head->next;
        ListNode* tmp=nullptr;
        pre->next=nullptr;
        while(cur!=nullptr){
            tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        vector<int> ans;
        while(pre!=nullptr){
            ans.push_back(pre->val);
            pre=pre->next;
        }
        return ans;
    }
};